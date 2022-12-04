#define __GNU_SOURCE
#define _DAI_NO_LIBRARIES
#include "../../stdlib/Daisho.h"

int
main(void) {
    setbuf(stdout, NULL);

    char valid[80];
    char space[80];
    char* buf = space + 20;
    const char bead[] = {'B', 'E', 'A', 'D'};

#define TEST_TYPETOA(t, func, fmt)                                                               \
    /* For every possible value of the type */                                                   \
    for (t i = _DAI_MIN_OF_TYPE(t); i <= _DAI_MAX_OF_TYPE(t); i++) {                           \
        if (!(i % 100000000)) printf(fmt "\n", i);                                               \
        /* Initialize the array to known values (BEAD repeating)  */                             \
        for (size_t j = 0; j < 80; j++) space[j] = bead[j % 4];                                  \
                                                                                                 \
        /* Run the function */                                                                   \
        int printed = sprintf(valid, fmt, i);                                                    \
        size_t ret = func(i, buf);                                                               \
                                                                                                 \
        /* Validate the return */                                                                \
        if ((size_t)printed != ret) {                                                                    \
            printf("Expected %d characters printed for " fmt ", but printed %zu.\n", printed, i, \
                   ret);                                                                         \
            write(STDOUT_FILENO, space, 80);                                                     \
            puts("");                                                                            \
            exit(1);                                                                             \
        }                                                                                        \
                                                                                                 \
        /* Make sure it printed right */                                                         \
        for (size_t j = 0; j < ret; j++) {                                                       \
            if (buf[j] != valid[j]) {                                                            \
                printf("At position %zu, expected %c but got %c.\n", j, valid[j], buf[j]);       \
                printf("Expected: %s\nGot: %s\n", valid, buf);                                   \
                exit(1);                                                                         \
            }                                                                                    \
        }                                                                                        \
                                                                                                 \
        /* Check for memory corruption before. */                                                \
        for (size_t j = 0; j < 20; j += 4) {                                                     \
            if (space[j] != bead[j % 4]) {                                                       \
                printf("Previous memory corrupted. All memory:\n");                              \
                write(STDOUT_FILENO, space, 80);                                                 \
                puts("");                                                                        \
                exit(1);                                                                         \
            }                                                                                    \
        }                                                                                        \
                                                                                                 \
        /* Check for memory corruption after. */                                                 \
        for (size_t j = ret; j < 60; j++) {                                                      \
            if (buf[j] != bead[j % 4]) {                                                         \
                printf("Subsequent memory corrupted. All memory:\n");                            \
                write(STDOUT_FILENO, space, 80);                                                 \
                puts("");                                                                        \
                exit(1);                                                                         \
            }                                                                                    \
        }                                                                                        \
    }
    TEST_TYPETOA(long, _Dai_ltoa, "%ld");
    TEST_TYPETOA(unsigned long, _Dai_ultoa, "%lu");
}

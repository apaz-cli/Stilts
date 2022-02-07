#define __STILTS_EMBED_PYTHON 1
#include "../../stdlib/Stilts.h"

int
main(int argc, char** argv) {
    __Stilts_pre_main(argc, argv);

#if __STILTS_EMBED_PYTHON
    __Stilts_py_eval((char*)"print('SUCCESS')");
#else
    puts("SUCCESS");
#endif

    __Stilts_exit(0);
}

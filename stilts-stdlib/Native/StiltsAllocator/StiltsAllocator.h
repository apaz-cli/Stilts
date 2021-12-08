#pragma once
#ifndef __STILTS_STDLIB_ALLOCATOR
#define __STILTS_STDLIB_ALLOCATOR
#include "../StiltsStdInclude.h"

/******************/
/* Error Handling */
/******************/

/* Powers of two */
#define __STILTS_KILOBYTE (1024L)
#define __STILTS_MEGABYTE (1024L * 1024L)
#define __STILTS_GIGABYTE (1024L * 1024L * 1024L)
#define __STILTS_TERABYTE (1024L * 1024L * 1024L * 1024L)


#define __STILTS_ALLOC_ALIGNMENT _Alignof(max_align_t)


/* Decide what to do with these in the future. */
__STILTS_FN void*
__Stilts_malloc(size_t size, __STILTS_SRC_INFO_ARGS) {
    if (__STILTS_SANITY_CHECK) {
        /* Pass through OOM error. */
        void* ret = malloc(size);
        if (!ret) __Stilts_default_OOM(__STILTS_SRC_INFO_PASS);
        return ret;
    } else {
        __STILTS_SRC_INFO_IGNORE();
        return malloc(size);
    }
}

__STILTS_FN void*
__Stilts_realloc(void* ptr, size_t size, __STILTS_SRC_INFO_ARGS) {
    if (__STILTS_SANITY_CHECK) {
        void* ret = realloc(ptr, size);
        if (!ret) __Stilts_default_OOM(__STILTS_SRC_INFO_PASS);
        return ret;
    } else {
        __STILTS_SRC_INFO_IGNORE();
        return realloc(ptr, size);
    }
}

__STILTS_FN void*
__Stilts_calloc(size_t num, size_t size, __STILTS_SRC_INFO_ARGS) {
#if __STILTS_SANITY_CHECK
    if (!num) __STILTS_ERROR("Argument \"num\" to calloc() cannot be zero.");
    else if (!size) __STILTS_ERROR("Argument \"size\" to calloc() cannot be zero.");
#else
    __STILTS_SRC_INFO_IGNORE();
#endif

    void* result = calloc(num, size);

#if __STILTS_SANITY_CHECK
    if (!result) __Stilts_default_OOM(__STILTS_SRC_INFO_PASS);
#endif
    return result;
}

__STILTS_FN void
__Stilts_free(void* ptr, __STILTS_SRC_INFO_ARGS) {
    __STILTS_SRC_INFO_IGNORE();
    free(ptr);
}

#define STILTS_MALLOC(size)       __Stilts_malloc(size, __STILTS_SRC_INFO)
#define STILTS_REALLOC(ptr, size) __Stilts_realloc(ptr, size, __STILTS_SRC_INFO)
#define STILTS_CALLOC(num, size)  __Stilts_calloc(num, size, __STILTS_SRC_INFO)
#define STILTS_FREE(ptr)          __Stilts_free(ptr, __STILTS_SRC_INFO)


#endif /* __STILTS_STDLIB_ALLOCATOR */

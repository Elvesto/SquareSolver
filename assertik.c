#include "assertik.h"

#include <stdio.h>
#include <stdlib.h>


void fooAssert(const char *expr, const char *file, const char *func, int line) {
    do {
        fprintf(stderr, "Assertation Failed: %s\nFile: %s,\nFunction: %s,\nLine: %d\n", expr, file, func, line);
        abort();
    } while (0);
}
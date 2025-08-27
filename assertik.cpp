#include "assertik.h"

#include <stdio.h>
#include <stdlib.h>

#include "colors.h"


void fooAssert(bool condition, const char *expr, const char *file, const char *func, int line) {
    if (! (condition)) {
        fprintf(stderr, RED_BACK "Assertation Failed: %s" RESET "\nFile: %s,\nFunction: %s,\nLine: %d"
            "\n", expr, file, func, line);
        abort();
    }
}
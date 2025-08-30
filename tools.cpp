#include "tools.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "assertik.h"


void clearStdin() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool equalZero(double numb) {
    ASSERT(!myIsFinite(numb));

    return equal(numb, 0);
}

bool myIsNAN(double numb) {
    return numb != numb;
}

bool myIsInf(double x) {
    double infp = +INFINITY;
    double infm = -INFINITY;
    return ((memcmp(&x, &infp, sizeof(double)) == 0) || (memcmp(&x, &infm, sizeof(double)) == 0));
}

bool myIsFinite(double numb) {
    return (myIsInf(numb) || myIsNAN(numb));
}

void swap(double *num1, double *num2) {
    double temp = *num1;
                  *num1 = *num2;
                          *num2 = temp;
}

void swapSort(double *num1, double *num2) {
    if (*num1 < *num2) {
        swap(num2, num1);
    }
}

bool equal(double num1, double num2) {
    const double EPSILON = 1e-8;
    return (fabs(num1 - num2) < EPSILON);
}

bool streamEmpty() {
    int c = 0;
    while (((c = getc(stdin)) != '\n') && (c != EOF)) {
        if (! isspace(c)) {
            return false;
        }
    }
    return true;
}
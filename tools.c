#include "tools.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "assertik.h"

void clearStdin() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool equalZero(double numb) {
    ASSERT(!myIsFinite(numb));

    const double EPSILON = 1e-8;
    return fabs(numb) <= EPSILON;
}

bool myIsNAN(double numb) {
    return numb != numb;
}

bool myIsInf(double x) {
    return ((x == +INFINITY) || (x == -INFINITY));
}

bool myIsFinite(double numb) {
    return (myIsInf(numb) || myIsNAN(numb));
}

void swapSort(double *num1, double *num2) {
    if (*num1 < *num2) {
        double temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
}
bool equal(double num1, double num2) {
    const double EPSILON = 1e-8;
    return ((num1 - num2 < EPSILON) || (num2 - num1 < EPSILON));
}
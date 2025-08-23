#include "solvers.h"

#include <math.h>

#include "assertik.h"
#include "tools.h"

// FIXME доки в хедеры

double discriminant(double a, double b, double c) {
    ASSERT(!(myIsFinite(a)));
    ASSERT(!(myIsFinite(b)));
    ASSERT(!(myIsFinite(c)));
    
    return b*b - 4*a*c;
}

void solverWithOneRoot(double a, double b, double* x) {
    ASSERT(!(myIsFinite(a)));
    ASSERT(!(myIsFinite(b)));
    ASSERT(x != NULL);

    *x = (-b) / (2 * a);
    *x = equalZero(*x) ? 0 : *x;
}

void solverWithTwoRoots(double a, double b, double D, double* x1, double* x2) {
    ASSERT(!(myIsFinite(a)));
    ASSERT(!(myIsFinite(b)));
    ASSERT(!(myIsFinite(D)));
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);

    D = sqrt(D);
    *x1 = (-b + D)/2.0/a;
    *x2 = (-b - D)/2.0/a;
}

NumberOfRoots solverQuad(double a, double b, double c, double* x1, double* x2) {
    ASSERT(!(myIsFinite(a)));
    ASSERT(!(myIsFinite(b)));
    ASSERT(!(myIsFinite(c)));
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);

    double D = discriminant(a, b, c);
    if (D < 0)
        return ZERO;
    else if (equalZero(D)) {
        solverWithOneRoot(a, b, x1);
        return ONE;
    } else {
        solverWithTwoRoots(a, b, D, x1, x2);
        return TWO;
    }
}

double solverLineal(double b, double c) {
    ASSERT(!(myIsFinite(b)));
    ASSERT(!(myIsFinite(c)));
    double root = -c/b;
    return (!equalZero(root)) ? root : 0;
}

NumberOfRoots solverAll(double a, double b, double c, double* x1, double *x2) {
    ASSERT(!(myIsFinite(a)));
    ASSERT(!(myIsFinite(b)));
    ASSERT(!(myIsFinite(c)));
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);

    if (!equalZero(a)) {
        return solverQuad(a, b, c, x1, x2);
    } else if (equalZero(a) && !equalZero(b)) {
        *x1 = solverLineal(b, c);
        return ONE;
    } else if (equalZero(a) && equalZero(b) && equalZero(c)) {
        return INFINITE;
    } else {
        return ZERO;
    }
}
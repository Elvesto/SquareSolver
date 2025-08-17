typedef enum NumberOfRoots {
    ZERO = 0,
    ONE,
    TWO,
    INFINITE
} NumberOfRoots;

double dis(double a, double b, double c) {
    return b*b - 4*a*c;
}

void solverWithOneRoot(double a, double b, double* x) {
    *x = (-b) / (2 * a);
}

void solverWithTwoRoots(double a, double b, double D, double* x1, double* x2) {
    D = sqrt(D);
    *x1 = (-b + D)/2.0/a;
    *x2 = (-b - D)/2.0/a;
}

NumberOfRoots solverQuad(double a, double b, double c, double* x1, double* x2) {
    double D = dis(a, b, c);
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
    return -c/b;
}

NumberOfRoots solverAll(double a, double b, double c, double* x1, double *x2) {
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

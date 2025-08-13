#include <stdio.h>
#include <math.h>
#include <stdbool.h>


const double EPSILON = 1e-10;

enum NumberOfRoots {
    ZERO = 0,
    ONE,
    TWO,
    INFINITE
};

double dis(double a, double b, double c);
void solver1(double a, double b, double* x);
void solver2(double a, double b, double D, double* x1, double* x2);
bool equalZero(double numb);
enum NumberOfRoots solverQuad(double a, double b, double c, double* x1, double* x2);
double solverLineal(double b, double c);
enum NumberOfRoots solverAll(double a, double b, double c, double* x1, double* x2);


int main() {
    double a, b, c;
    while (1) {
        scanf("%lf%lf%lf", &a, &b, &c);
        double x1, x2;
        int numbRoots = solverAll(a, b, c, &x1, &x2);
        switch (numbRoots) {
            case ZERO:
                printf("No real solution\n");
                break;
            case ONE:
                printf("%lf\n", x1);
                break;
            case TWO:
                printf("%lf %lf\n", x1, x2);
                break;
            case INFINITE:
                printf("Infinite solution\n");
                break;
            default:
                printf("razrab daun");
        }
    }

}


double dis(double a, double b, double c) {
    return b*b - 4*a*c;
}

void solver1(double a, double b, double* x) {
    *x = (-b) / (2 * a);
}

void solver2(double a, double b, double D, double* x1, double* x2) {
    D = sqrt(D);
    *x1 = (-b + D)/2.0/a;
    *x2 = (-b - D)/2.0/a;
}

bool equalZero(double numb) {
    return fabs(numb) <= EPSILON;
}

enum NumberOfRoots solverQuad(double a, double b, double c, double* x1, double* x2) {
    double D = dis(a, b, c);
    if (D < 0)
        return ZERO;
    else if (equalZero(D)) {
        solver1(a, b, x1);
        return ONE;
    } else {
        solver2(a, b, D, x1, x2);
        return TWO;
    }
}

double solverLineal(double b, double c) {
    return -c/b;
}
enum NumberOfRoots solverAll(double a, double b, double c, double* x1, double *x2) {
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

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double EPSILON = 1e-10;


double dis(double a, double b, double c);
void solver1(double a, double b, double* x);
void solver2(double a, double b, double D, double* x1, double* x2);
bool equalZero(double numb);
void solverQuad(double a, double b, double c);
void solverLineal(double b, double c);
int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (!equalZero(a)) {
        solverQuad(a, b, c);
    }else if (equalZero(a) && !equalZero(b)) {
        solverLineal(b, c);
    }
    else if (equalZero(a) && equalZero(b) && equalZero(c)) {
        printf("Infinite solution");
    }
    else {
        printf("No real solution");
    }
}



double dis(double a, double b, double c) {
    return b*b - 4*a*c;
}
void solver1(double a, double b, double* x) {
    *x = (-b)/2.0/a;
}
void solver2(double a, double b, double D, double* x1, double* x2) {
    *x1 = (-b + sqrt(D))/2.0/a;
    *x2 = (-b - sqrt(D))/2.0/a;
}
bool equalZero(double numb) {
    return fabs(numb) <= EPSILON;
}
void solverQuad(double a, double b, double c) {
    double D = dis(a, b, c);
    if (D < 0)
        printf("No real solution");
    else if (equalZero(D)) {
        double x;
        solver1(a, b, &x);
        printf("%lf", x);
    }
    else {
        double x1, x2;
        solver2(a, b, D, &x1, &x2);
        printf("%lf %lf", x1, x2);
    }
}
void solverLineal(double b, double c) {
    printf("%lf", -c/b);
}

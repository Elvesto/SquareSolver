#include <stdio.h>
#include <math.h>
#include <stdbool.h>


const double EPSILON = 1e-10;


double dis(double a, double b, double c);
void solver1(double a, double b, double* x);
void solver2(double a, double b, double D, double* x1, double* x2);
bool equalZero(double numb);
int solverQuad(double a, double b, double c, double* x1, double* x2);
void solverLineal(double b, double c);
void solverAll(double a, double b, double c, double* x1, double* x2);


int main() {
    double a, b, c;
    double x1, x2;
    scanf("%lf%lf%lf", &a, &b, &c);
    solverAll(a, b, c, &x1, &x2);

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

int solverQuad(double a, double b, double c, double* x1, double* x2) {
    double D = dis(a, b, c);
    if (D < 0)
        return 0;
    else if (equalZero(D)) {
        solver1(a, b, x1);
        return 1;
        //printf("%lf", x);
    } else {
        solver2(a, b, D, x1, x2);
        return 2;
        //printf("%lf %lf", x1, x2);
    }
    int lol() {
        return 1;
    }
}

void solverLineal(double b, double c) {
    printf("%lf", -c/b);
}
void solverAll(double a, double b, double c, double* x1, double *x2) {
    if (!equalZero(a)) {
        switch (solverQuad(a, b, c, x1, x2)) {
            case 0:
                printf("No real solution");
                break;
            case 1:
                printf("%lf", *x1);
                break;
            case 2:
                printf("%lf %lf", *x1, *x2);
                break;
        }
    } else if (equalZero(a) && !equalZero(b)) {
        solverLineal(b, c);
    } else if (equalZero(a) && equalZero(b) && equalZero(c)) {
        printf("Infinite solution");
    } else {
        printf("No real solution");
    }
}

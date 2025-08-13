#include <stdio.h>
#include <math.h>
#include <stdbool.h>


const double EPSILON = 1e-10;


double dis(double a, double b, double c);
void solver1(double a, double b, double* x);
void solver2(double a, double b, double D, double* x1, double* x2);
bool equalZero(double numb);
int solverQuad(double a, double b, double c, double* x1, double* x2);
double solverLineal(double b, double c);
int solverAll(double a, double b, double c, double* x1, double* x2);


int main() {
    double a, b, c;
    double x1, x2;
    scanf("%lf%lf%lf", &a, &b, &c);
    switch (solverAll(a, b, c, &x1, &x2)) {
        case 0:
            printf("No real solution");
            break;
        case 1:
            printf("%lf", x1);
            break;
        case 2:
            printf("%lf %lf", x1, x2);
            break;
        case 3:
            printf("Infinite solution");
            break;
        default:
            printf("razrab daun");
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

int solverQuad(double a, double b, double c, double* x1, double* x2) {
    double D = dis(a, b, c);
    if (D < 0)
        return 0;
    else if (equalZero(D)) {
        solver1(a, b, x1);
        return 1;
    } else {
        solver2(a, b, D, x1, x2);
        return 2;
    }
    int lol() {
        return 1;
    }
}

double solverLineal(double b, double c) {
    return -c/b;
}
int solverAll(double a, double b, double c, double* x1, double *x2) {
    if (!equalZero(a)) {
        return solverQuad(a, b, c, x1, x2);
    } else if (equalZero(a) && !equalZero(b)) {
        *x1 = solverLineal(b, c);
        return 1;
    } else if (equalZero(a) && equalZero(b) && equalZero(c)) {
        return 3;
    } else {
        return 0;
    }
}

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "const.h"
#include "tools.h"



typedef enum NumberOfRoots {
    ZERO = 0,
    ONE, 
    TWO,
    INFINITE
} NumberOfRoots;


#include "solvers.h"



/*double dis(double a, double b, double c);
void solver1(double a, double b, double* x);
void solver2(double a, double b, double D, double* x1, double* x2);
bool equalZero(double numb);
NumberOfRoots solverQuad(double a, double b, double c, double* x1, double* x2);
double solverLineal(double b, double c);
NumberOfRoots solverAll(double a, double b, double c, double* x1, double* x2);
void clean_stdin();
*/

int main() {
    double a, b, c;

    while (1) {
        int n = scanf("%lf%lf%lf", &a, &b, &c);
        if (n != 3) {
            if (getc(stdin) == 'q') {
                printf("Exit the program...\n");
                break;
            }
            else {
                clean_stdin();
                printf("format: a b c\n");
                printf("ax^2 + bx + c = 0\n");
                continue;
            }
        }

        double x1, x2;
        NumberOfRoots numbRoots = solverAll(a, b, c, &x1, &x2);
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






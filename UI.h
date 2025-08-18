#include "solvers.h"

typedef enum State {
    QUIT = 0,
    PROCESS,
    ERROR
} State;

State getCoef(double* a, double* b, double* c);
void printSolution(double x1, double x2, NumberOfRoots numbRoots);

State getCoef(double* a, double* b, double* c) {
    int n = scanf("%lf%lf%lf", a, b, c);
    if (n != 3) {
        if (getc(stdin) == 'q') {
            printf("Exit the program...\n");
            return QUIT;
        }
        else {
            clean_stdin();
            printf("format: a b c\n");
            printf("ax^2 + bx + c = 0\n");
            return ERROR;
        }
    } else {
        return PROCESS;
    }
}

void printSolution(double x1, double x2, NumberOfRoots numbRoots) {
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

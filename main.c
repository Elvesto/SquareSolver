#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "assertik.h"
#include "colors.h"
#include "tools.h"
#include "solvers.h"
#include "UI.h"

/*void solverTester() {
    double x1 = 0, x2 = 0;
    int nroots = solverAll(1, -7, 12, &x1, &x2);
    if (! (nroots == 2 && x1 == 4 && x2 == 3))
        printf("FALED: solverAll(1, -7, 12...). Count roots - %d, x1 = %lg, x2 = %lg(should be x1 = 4, x2 = 3\n)", nroots, x1, x2);
    nroots = solverAll(1, 1, 1, &x1, &x2);
    if (! (nroots == 0))
        printf("FALED: solverAll(1, 1, 1...). Count roots - %d(should be count roots = 0\n)", nroots);
    nroots = solverAll(0, 0, 0, &x1, &x2);
    if (! (nroots == 3))
        printf("FALED: solverAll(0, 0, 0...). Count roots - %d, x1 = %lg, x2 = %lg(should be count roots = infinite(3)\n)", nroots, x1, x2);
    printf("OK\n");
}*/

int main() {
    //solverTester();
    while (1) {
        printf(YELLOW BOLD "Enter the coefficients of the equation" RESET"\n");
        double a = 0, b = 0, c = 0;
        State state = PROCESS;

        state = getCoef(&a, &b, &c);

        if (state == ERROR)
            continue;
        else if (state == QUIT) {
            break;
        }

        double x1 = 0, x2 = 0;
        NumberOfRoots numbRoots = solverAll(a, b, c, &x1, &x2);
        printSolution(x1, x2, numbRoots);
    }
    return 0;
}


/*enum result {
    BOLSHE = 0,
    MENSHE,
    RAVNO
}
enum result equals(double a, double b) {
    if (a - b > EPSILON) {
        return BOLSHE
    }
    else if (b - a > EPSILON)
    else if (fabs(a - b)
}
if equals(kakayto huina) == BOLSHE*/
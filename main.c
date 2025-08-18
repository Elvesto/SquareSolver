#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "tools.h"

#ifndef SOLVERS_H
#define SOLVERS_H
#include "solvers.h"
#endif

#include "UI.h"


int main() {
    while (1) {
        double a, b, c;
        State state;

        state = getCoef(&a, &b, &c);

        if (state == ERROR)
            continue;
        else if (state == QUIT)
            break;

        double x1, x2;
        NumberOfRoots numbRoots = solverAll(a, b, c, &x1, &x2);
        printSolution(x1, x2, numbRoots);
    }
    return 0;
}

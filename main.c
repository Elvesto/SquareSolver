#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "tools.h"
#include "solvers.h"
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
        printSolution(a, b, c, numbRoots);
    }
    return 0;
}

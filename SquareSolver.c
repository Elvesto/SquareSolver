#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "tools.h"
#include "solvers.h"
#include "UI.h"


int main() {
    State state;
    double a, b, c;
    while (1) {

        getCoef(&a, &b, &c, &state);

        if (state == ERROR)
            continue;
        else if (state == QUIT)
            break;

        printSolution(a, b, c);

    }
    return 0;

}

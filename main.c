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

        printSolution(a, b, c);
    }
    return 0;
}

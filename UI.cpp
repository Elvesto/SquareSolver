#include "UI.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "assertik.h"
#include "colors.h"
#include "tools.h"
#include "test.h"

State getCoef(double* a, double* b, double* c) {
    ASSERT(a != NULL);
    ASSERT(b != NULL);
    ASSERT(c != NULL);

    int n = scanf("%lf%lf%lf", a, b, c);
    if (n != 3) {
        if (getc(stdin) == 'q') {
            printf(BLUE_BACK KURSIV "Exit the program..." RESET "\n");
            return QUIT;
        }
        else if ((getc(stdin) != EOF)) {
            clearStdin();
            printf(RED BOLD "format: a b c\n");
            printf("ax^2 + bx + c = 0\n" RESET);
            return ERROR;
        }
        else {
            return QUIT;
        }
    } else {
        return PROCESS;
    }
}

void printSolution(double x1, double x2, NumberOfRoots numbRoots) {
    ASSERT(!(myIsFinite(x1)));
    ASSERT(!(myIsFinite(x2)));
    
    switch (numbRoots) {
        case ZERO:
            printf(UNDERLINE "No real solution" RESET"\n");
            break;
        case ONE:
            printf(UNDERLINE "%lf" RESET "\n", x1);
            break;
        case TWO:
            printf(UNDERLINE "%lf %lf" RESET "\n", x1, x2);
            break;
        case INFINITE:
            printf(UNDERLINE "Infinite solution" RESET "\n");
            break;
        default:
            ASSERT(0 && CYAN_BACK "razrab daun" RESET);
    }
}


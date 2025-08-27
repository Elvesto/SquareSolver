#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "assertik.h"
#include "colors.h"
#include "tools.h"
#include "solvers.h"
#include "UI.h"
#include "test.h"
#include "modes.h"

int main(int argc, char *argv[]) {
    char *file = NULL;
    Mode mode = chooseMode(argc, argv, &file);
    if (mode.help == true) {
        help();
    }
    if (mode.test == true) {
        int failed = testAll(file);
        printf(YELLOW "--test" RED "          Count failed tests = %d" RESET"\n", failed);
    }
    if (mode.interactive == true) {
        interactive();
    }

    //printf(CYAN_BACK "GIT COMMIT:)" RESET "\n");

    return 0;
}


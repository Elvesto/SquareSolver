#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "loger.h"
#include "colors.h"
#include "test.h"
#include "modes.h"


int main(const int argc, const char *argv[]) {
    openLogFile();
    printMessage("Starting program - %d\n", INFO, 1, 1);
    char *file = NULL;
    Mode mode = chooseMode(argc, argv, &file);
    if (mode.help) {
        help();
    }
    if (mode.test) {
        int failed = testAll(file);
        printf(YELLOW "--test" RED "          Count failed tests = %d" RESET"\n", failed);
    }
    if (mode.interactive) {
        interactive();
    }

    //printf(CYAN_BACK "GIT COMMIT:)" RESET "\n");
    closeLogFile();
    return 0;
}
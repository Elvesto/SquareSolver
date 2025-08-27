#include "modes.h"

#include <stdio.h>
#include <getopt.h>
#include <string.h>

#include "solvers.h"
#include "UI.h"
#include "colors.h"


void help() {
    printf(MAGENTA ""
        "--help                                  prints what command arguments there are \n" 
        "--interactive                           input user mode\n"
        "--test                                  input file mode(for exam or testing.) argument - name file\n"
    RESET);
}

void interactive() {
    printf(GREEN KURSIV "--interactive          Starting..." RESET "\n");
    while (1) {
        printf(CYAN BOLD "Enter the coefficients of the equation" RESET"\n");
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
}
Mode chooseMode(int argc, char *argv[], char* *file) {
    Mode mode = {0};
    int opt = 0;
    while (1) {
        const struct option long_options[] = {
            {"help",        0, 0, 'h'},
            {"test",        1, 0, 't'},
            {"interactive", 0, 0, 'i'},
            {0, 0, 0, 0}
        };
        opt = getopt_long(argc, argv, "ht:i", long_options, NULL);
        if (opt == -1)
            break;
        switch (opt) {
            case 'h':
                mode.help = true;
                break;
            case 't':
                mode.test = true;
                if (optarg != NULL) {
                    *file = optarg;
                }
                break;
            case 'i':
                mode.interactive = true;
                break;
            case '?':
                fprintf(stdout, "Invalid argument");
                break;
            default:
                break;
        }
    }
    /*for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) 
            mode.help = true;
        else if (strcmp(argv[i], "--test") == 0) 
            mode.test = true;
        else if (strcmp(argv[i], "--interactive") == 0)
            mode.interactive = true;
        else {
            printf("This argument no exist\n");
        }
    }*/
    if (mode.help == false && mode.test == false && mode.interactive == false) {
        printf(MAGENTA "Transition to normal mode...\n" RESET);
        mode.interactive = true;
    }
    return mode;
            
}
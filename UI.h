typedef enum State {
    QUIT = 0,
    PROCESS,
    ERROR
} State;

void getCoef(double* a, double* b, double* c, State* state) {
    int n = scanf("%lf%lf%lf", a, b, c);
    if (n != 3) {
        if (getc(stdin) == 'q') {
            printf("Exit the program...\n");
            *state = QUIT;
        }
        else {
            clean_stdin();
            printf("format: a b c\n");
            printf("ax^2 + bx + c = 0\n");
            *state = ERROR;
        }
    } else {
        *state = PROCESS;
    }
}

void printSolution(double a, double b, double c)
{
    double x1, x2;
    NumberOfRoots numbRoots = solverAll(a, b, c, &x1, &x2);
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

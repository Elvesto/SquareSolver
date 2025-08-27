#ifndef TEST_H_
#define TEST_H_

struct Equation {
    double a, b, c;
    int countRoots;
    double x1, x2;
};

int test(Equation equation);
int testAll(char *f);


#endif // TEST_H_
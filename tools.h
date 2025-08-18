#ifndef TOOLS_H_
#define TOOLS_H_

void clean_stdin();
bool equalZero(double numb);

void clean_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool equalZero(double numb) {
    const double EPSILON = 1e-8;
    return fabs(numb) <= EPSILON;
}



#endif

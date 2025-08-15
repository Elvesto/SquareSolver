

void clean_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


bool equalZero(double numb) {
    return fabs(numb) <= EPSILON;
}

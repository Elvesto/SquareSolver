#ifndef MODES_H_
#define MODES_H_

struct Mode {
    bool help;
    bool interactive; 
    bool test;
};

void help();
void interactive();
Mode chooseMode(int argc, char *argv[], char* *file);


#endif
#ifndef MODES_H_
#define MODES_H_

struct Mode {
    bool help;
    bool interactive; 
    bool test;
};

/**
 * @brief Печатает информацию --help
 */
void help();

/**
 * @brief Входит в режим --interactive
 */
void interactive();

/**
 * @brief Обрабатывает аргументы командной строки
 */
Mode chooseMode(const int argc, const char *argv[], char **file);


#endif // MODES_H_

#ifndef TEST_H_
#define TEST_H_

struct Equation {
    double a, b, c;
    int countRoots;
    double x1, x2;
};

/**
 * @param [in] reference Значения сравниваемые с значениями полученными в ходе выполнения программы
 * @return Ф-ия возвращает количество несовпадений значений
 */
int test(Equation reference);

/**
 * @param [in] filename Название текстового файла откуда будут сравниваться значения
 * @return Ф-ия возвращает количество несовпадений значений
 */
int testAll(char *fileName);

bool checkRoots(double xref, double x);

#endif // TEST_H_
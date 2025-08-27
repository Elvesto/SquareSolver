#ifndef UI_H_
#define UI_H_

#include "solvers.h"


typedef enum State {
    QUIT = 0,
    PROCESS,
    ERROR
} State;



/**
 * @param [out] a Указатель на коэфициент, чтобы его получить
 * @param [out] b Указатель на коэфициент, чтобы его получить
 * @param [out] c Указатель на коэфициент, чтобы его получить
 * @return Функция возвращает состояние программы, 
 * QUIT - Выход из программы, 
 * PROCESS - Продолжение выполнение программы, 
 * ERROR - Выход из программы
 */
State getCoef(double* a, double* b, double* c);

/**
 * @param [in] x1 Первый корень
 * @param [in] x2 Второй корень
 * @param [in] numbRoots Количество корней, который сущесвуют для данного уравнения
*/
void printSolution(double x1, double x2, NumberOfRoots numbRoots);


#endif // UI_H_
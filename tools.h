#ifndef TOOLS_H_
#define TOOLS_H_

/**
 * @note Очищает входной поток
 */
void clearStdin();

/**
 * @param [in] numb число сравниваемое с нулём
 * @return Ф-ия возвращает равно ли число нулю 
 */
bool equalZero(double numb);

/**
 * @param [in] numb число сравниваемое с NAN
 * @return Ф-ия возвращает является ли число NAN
 */
bool myIsNAN(double numb);

/**
 * @param [in] numb число проверяемое на равенство бесконечности
 * @return Ф-ия возвращает равно ли число бесконечности 
 */
bool myIsInf(double x);

/**
 * @param [in] numb число сравниваемое с NAN и бесконечностью
 * @return Ф-ия возвращает является ли число NAN или бесконечностью
 */
bool myIsFinite(double numb);

/**
 * @brief меняет местами две переменные типа double 
 */
void swapSort(double *num1, double *num2);

/**
 * @brief сравнивает две переменные типа double
 * @return Ф-ия возвращает true если числа равны с учетом погрешности EPSILON, false - если нет
*/
bool equal(double num1, double num2);


#endif // TOOLS_H_
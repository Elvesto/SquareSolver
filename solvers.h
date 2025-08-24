#ifndef SOLVERS_H_
#define SOLVERS_H_

typedef enum NumberOfRoots {
    ZERO = 0,
    ONE,
    TWO,
    INFINITE
} NumberOfRoots;

///----------------------------------------
/// @brief goida
/// @param [in] a коэффициент уравнения
/// @param [in] b коэффициент уравнения
/// @param [in] c коэффициент уравнения
/// @return Ф-ия возвращает значение дискриминант
///----------------------------------------
double discriminant(double a, double b, double c);

//----------------------------------------
//! @param [in] a коэффициент уравнения
//! @param [in] b коэффициент уравнения
//! @param [out] x Единственный корень уравнения
//----------------------------------------
void solverWithOneRoot(double a, double b, double* x);

//----------------------------------------
//! @param [in] a коэффициент уравнения
//! @param [in] b коэффициент уравнения
//! @param [in] D Дискриминант уравнения
//! @param [out] x1 Первый корень уравнения
//! @param [out] x2 Второй корень уравнения
//----------------------------------------
void solverWithTwoRoots(double a, double b, double D, double* x1, double* x2);

//----------------------------------------
//! @param [in] a коэффициент уравнения
//! @param [in] b коэффициент уравнения
//! @param [in] c коэффициент уравнения
//! @param [out] x1 корень уравнения
//! @param [out] x2 корень уравнения
//! @return Ф-ия возвращает количество корней 
//----------------------------------------
NumberOfRoots solverQuad(double a, double b, double c, double* x1, double* x2);

//----------------------------------------
//! @param [in] b коэффициент уравнения
//! @param [in] c коэффициент уравнения
//! @return Ф-ия возвращает корень линейного уравнения
//----------------------------------------
double solverLineal(double b, double c);

//----------------------------------------
//! @param [in] a коэффициент уравнения
//! @param [in] b коэффициент уравнения
//! @param [in] c коэффициент уравнения
//! @param [out] x1 Корень уравнения
//! @param [out] x2 Корень уравнения
//! @return Ф-ия возвращает количество корней
//----------------------------------------
NumberOfRoots solverAll(double a, double b, double c, double* x1, double *x2);


#endif // SOLVERS_H_
#ifndef ASSERTIK_H_
#define ASSERTIK_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/**
 * @note функция-обертка макроса ASSERT
*/
void assertImpl(bool condition, const char *expr, const char *file, const char *func, int line);

#define ASSERT(expr) assertImpl(expr, #expr, __FILE__, __FUNCTION__, __LINE__)
    
#endif // ASSERTIK_H_
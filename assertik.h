#ifndef ASSERTIK_H_
#define ASSERTIK_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//-------------------------------------------
//! @note функция-обертка макроса ASSERT
//-------------------------------------------
void fooAssert(const char *expr, const char *file, const char *func, int line);

// FIXME можно всё вместе с циклом заменить на вызов функции
// FIXME почитать что происходит до main и после
/*#define ASSERT(expr)                                                            \
    do {                                                                        \
        if (!(expr))                                                            \
            fooAssert(#expr, __FILE__, __FUNCTION__, __LINE__);                 \
    } while(0)*/
#define ASSERT(expr) \
    if (! (expr)) \
        fooAssert(#expr, __FILE__, __FUNCTION__, __LINE__) \
    
#endif // ASSERTIK_H_
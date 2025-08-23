#ifndef ASSERTIK_H_
#define ASSERTIK_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// FIXME docs
// FIXME написать функцию ассерта и вызывать в макросе
// FIXME почитать про отличие  между exit и abort
// FIXME выводить в какой функции упал ассерт
// FIXME header guerd


//-------------------------------------------
//! @note функци-обертка макроса ASSERT
//-------------------------------------------
void fooAssert(const char *expr, const char *file, const char *func, int line);

#define ASSERT(expr)                                                            \
    do {                                                                        \
        if (!(expr))                                                            \
            fooAssert(#expr, __FILE__, __FUNCTION__, __LINE__);                 \
    } while(0)

    
#endif // ASSERTIK_H_
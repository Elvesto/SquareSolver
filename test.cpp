#include "test.h"

#include <stdio.h>
#include <math.h>

#include "solvers.h"
#include "tools.h"
#include "colors.h"

int test(Equation equation) {
   double x1 = 0, x2 = 0;
   int nroots = solverAll(equation.a, equation.b, equation.c, &x1, &x2);

   if (! (nroots == equation.countRoots && \
      (equal(x1, equation.x1) || myIsNAN(equation.x1)) && \
      (equal(x2, equation.x2) || myIsNAN(equation.x2)))) {
      printf(RED_BACK "FALED:" RESET
         " Count roots - %d, x1 = %lg, x2 = %lg"
         "(should be x1 = %lg,x2 = %lg,count roots = %d)" RESET
         "\n",nroots, x1, x2, equation.x1, equation.x2, equation.countRoots);
      return 0;
   }
   return 1;
}

int testAll(char* f) {
   int failed = 0;
   /*if (!inFile) {
      Equation testEquations[] = { 
         {.a =  1,    .b = -7,  .c =  12,    .countRoots = 2,        .x1 = 4,       .x2 = 3     },
         {.a =  1,    .b =  1,  .c =  1,     .countRoots = 0,        .x1 = NAN,     .x2 = NAN   },
         {.a =  0,    .b =  0,  .c =  0,     .countRoots = INFINITE, .x1 = NAN,     .x2 = NAN   },
         {.a = -1,    .b =  4,  .c =  0,     .countRoots = 2,        .x1 = 4,       .x2 = 0     },
         {.a =  1,    .b = -2,  .c =  1,     .countRoots = 1,        .x1 = 1,       .x2 = NAN   },
         {.a =  0,    .b =  0,  .c =  1,     .countRoots = 0,        .x1 = NAN,     .x2 = NAN   },
         {.a =  0,    .b =  5,  .c = -5,     .countRoots = 1,        .x1 = 1,       .x2 = NAN   },
         {.a =  1,    .b = -0,  .c = -4,     .countRoots = 2,        .x1 = 2,       .x2 = -2    }
      };
      unsigned size = sizeof(testEquations) / sizeof(testEquations[0]);
      for (unsigned i = 0; i < size; i++) {
         failed += ! (test(testEquations[i]));
      }
   } else {*/
      FILE *file = fopen(f, "r");
      if (file == NULL) {
         fprintf(stdout, RED_BACK "File no open or is not exist" RESET  "\n");
         return -1;
      }
      Equation equation = {};
      while (fscanf(file, "%lf%lf%lf%d%lf%lf", &equation.a, &equation.b, &equation.c, 
         &equation.countRoots, &equation.x1, &equation.x2) != EOF) {
            failed += !(test(equation));
      }
      fclose(file);
   return failed;
}
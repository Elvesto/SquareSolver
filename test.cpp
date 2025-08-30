#include "test.h"

#include <stdio.h>
#include <math.h>

#include "solvers.h"
#include "tools.h"
#include "colors.h"

bool checkRoots(double xref, double x) {
   return (equal(x, xref) || (myIsNAN(xref) && myIsNAN(x)));
}

int test(Equation ref) {
   double x1 = 0, x2 = 0;
   int nroots = solverAll(ref.a, ref.b, ref.c, &x1, &x2);

   if ((nroots == ref.countRoots && checkRoots(x1, ref.x1) && checkRoots(x2, ref.x2))) {
      return 1;
   }
   printf(RED_BACK "FAILED:" RESET
         " Count roots - %d, x1 = %lg, x2 = %lg"
         "(should be x1 = %lg,x2 = %lg,count roots = %d)" RESET
         "\n",nroots, x1, x2, ref.x1, ref.x2, ref.countRoots);
   
   return 0;
}

int testAll(char *fileName) {
   FILE *file = fopen(fileName, "r");
   if (file == NULL) {
      fprintf(stdout, RED_BACK "File no open or is not exist" RESET  "\n");
      return -1;
   }
   
   Equation equation = {};
   int failed = 0;
   while (
      fscanf(
         file, "%lf%lf%lf%d%lf%lf", 
         &equation.a, &equation.b, &equation.c, 
         &equation.countRoots, &equation.x1, &equation.x2
      ) != EOF
   ) {
      failed += !(test(equation));
   }
   fclose(file);

   return failed;
}
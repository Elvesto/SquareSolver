#include "test.h"

#include <stdio.h>
#include <math.h>

#include "solvers.h"
#include "tools.h"

int test(double a, double b, double c, int countRootsRef, double x1ref, double x2ref) {
   double x1 = 0, x2 = 0;
   int nroots = solverAll(a, b, c, &x1, &x2);

   if (((countRootsRef == 0) && (0 != nroots)) || ((countRootsRef == INFINITE) && (nroots != INFINITE))) {
      printf("FALED: solverAll(...). Count roots - %d(should be count roots = %d)\n", nroots, countRootsRef);
      return 0;
   }
   if (countRootsRef == 1) {
      if (! (nroots == countRootsRef && equal(x1, x1ref))) {
         printf("FALED: solverAll(...). Count roots - %d, x1 = %lg, x2 = %lg(should be x1 = %lf, x2 = %lf, count roots = %d)\n", nroots, x1, x2, x1ref, x2ref, countRootsRef);
         return 0;
      }
   }
   if (! (nroots == countRootsRef && equal(x1, x1ref) && equal(x2, x2ref))) {
      printf("FALED: solverAll(...). Count roots - %d, x1 = %lg, x2 = %lg(should be x1 = %lf, x2 = %lf, count roots = %d)\n", nroots, x1, x2, x1ref, x2ref, countRootsRef);
      return 0;
   }
   return 1;
}

int testAll() {
   int faled = 0;
   faled += (! (test(1, -7, 12, 2, 4, 3)));
   faled += (! (test(1, 1, 1, 0, 0, 0)));
   faled += (! (test(0, 0, 0, INFINITE, 0, 0)));
   faled += (! (test(-1, 4, 0, 2, 4, 0)));
   faled += (! (test(1, -2, 1, 1, 1, 0)));
   return faled;
}
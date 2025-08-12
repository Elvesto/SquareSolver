#include <stdio.h>
#include <math.h>

double discr(double a, double b, double c);
void solver1(double* a, double* b);
void solver2(double* a, double* b, double D);
int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if ((a != 0))
    {
        double D = discr(a, b, c);
        if (D < 0)
            printf("Sad, equations haven`t solution");
        else if (D == 0)
        {
            solver1(&a, &b);
            printf("%lf", a);
        }
        else
        {
            solver2(&a, &b, D);
            printf("%lf %lf", a, b);
        }
    }
    else if (a == 0 && b != 0)
    {
        printf("%lf", -c/b);
    }
    else
    {
        printf("Sad, equations haven`t solution");
    }
}



double discr(double a, double b, double c)
{
    return b*b - 4*a*c;
}
void solver1(double* a, double* b)
{
    double c = *a;
    *a = (-(*b))/2.0/c;
}
void solver2(double* a, double* b, double D)
{
    float x1, x2;
    x1 = (-(*b) + sqrt(D))/2.0/ *a;
    x2 = (-(*b) - sqrt(D))/2.0/ *a;
    *a = x1;
    *b = x2;
}

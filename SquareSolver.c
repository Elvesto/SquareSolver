#include <stdio.h>
#include <math.h>

const double DIF = 1e-19;


double dis(double a, double b, double c);
void solver1(double a, double b, double* x);
void solver2(double a, double b, double D, double* x1, double* x2);
int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if ((fabs(a) > DIF))
    {
        double D = dis(a, b, c);
        if (D < 0)
            printf("No real solution");
        else if (fabs(D) <= DIF)
        {
            double x;
            solver1(a, b, &x);
            printf("%lf", x);
        }
        else
        {
            double x1, x2;
            solver2(a, b, D, &x1, &x2);
            printf("%lf %lf", x1, x2);
        }
    }
    else if (fabs(a) < DIF && fabs(b) > DIF)
    {
        printf("%lf", -c/b);
    }
    else if (fabs(a) < DIF && fabs(b) < DIF && fabs(c) < DIF)
    {
        printf("Infinite solution");
    }
    else
    {
        printf("No real solution");
    }
}



double dis(double a, double b, double c)
{
    return b*b - 4*a*c;
}
void solver1(double a, double b, double* x)
{
    *x = (-b)/2.0/a;
}
void solver2(double a, double b, double D, double* x1, double* x2)
{
    *x1 = (-b + sqrt(D))/2.0/a;
    *x2 = (-b - sqrt(D))/2.0/a;
}

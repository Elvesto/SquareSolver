#include <stdio.h>
#include <math.h>
#define and &&

int discr(int a, int b, int c);
void solver(int* a, int* b);
void solver(int* a, int* b, int D);
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if ((a != 0) and (b != 0) and (c != 0))
    {
        int D = discr(a, b, c);
        if (D < 0)
            printf("Sad, equations haven`t solver");
        else if (D == 0)
        {
            solver(&a, &b);
            printf("%d", a);
        }
        else
        {
            solver(&a, &b, D);
            printf("%d\t%d", a, b);
        }
    }
}



int discr(int a, int b, int c)
{
    return b*b - 4*a*c;
}
void solver(int* a, int* b)
{
    int c = *a;
    *a = (-(*b))/2.0/c;
}
void solver(int* a, int* b, int D)
{
    float x1, x2;
    x1 = (-(*b) + sqrt(D))/2.0/ *a;
    x2 = (-(*b) - sqrt(D))/2.0/ *a;
    *a = x1;
    *b = x2;
}

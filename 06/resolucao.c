#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pa(int, int, int);
int pg(int, int);
int sub(int, int, int);

int main ()
{
    printf("%d", sub(1, 100, 100));
    return 0;
}

int pa(int a0, int an, int n)
{
    int a = ((a0 + an) * n) /2;
    return a * a;
}

int pg(int a0, int an)
{
    int sum = 0;
    for(; a0 <= an; a0++) sum += a0 * a0;
    return sum;
}

int sub (int a0, int an, int n)
{
    int a, b;
    a = pa(a0, an, n);
    b = pg(a0, an);
    return a - b;
}

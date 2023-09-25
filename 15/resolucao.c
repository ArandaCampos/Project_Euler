#include <stdio.h>

long int sequence(int grid);

int main()
{
    printf("%ld\n", sequence(20));
    return 0;
}

long int sequence(int grid)
{
    /*
     * f(1)     = 2
     *
     * f(n)     = 1 * 2 * ... * 2n                    / (1 * 2 * ... * n)        * (1 * 2 * ... * n)
     * f(n + 1) = 1 * 2 * ... * 2n * (2n+1) * (2n+2) / (1 * 2 * ... * n * n+1 ) * (1 * 2 * ... * n * n+1)
     * ---------------------------------------------------------------------------------------------------
     * f(n + 1) = f(n)             * (2n+1) * (2n+2) / (                  n+1) * (                   n+1)
     *
     * f(n) = f(n-1) * 2n * (2n-1) / n * n
     * f(n) = f(n-1) * 2(2n-1) / n
     * f(n) = f(n-1) * (4n-2) / n
     */

    int n = 2;
    long int fn = 2;
    while (n <= grid)
    {
        fn = fn * (4 * n - 2)/ n;
        n++;
    }
    return fn;
}

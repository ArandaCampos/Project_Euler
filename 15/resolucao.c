#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t factorial(int n, int less);
uint64_t sequence(int grid);

int main()
{
    printf("%" PRIu64 "\n", sequence(20));
    return 0;
}

uint64_t factorial(int n, int less)
{
    uint64_t factorial = 1;
    if (n < 1) return 1;
    for (int i = less + 1; i <= n; i ++) factorial *= i;
    return factorial;
}

uint64_t sequence(int grid)
{
    /*
     * f(1) = 2
     * f(n) = 1 * 2 * ... * 2(n - 1) * ... * 2n / (1 * 2 * ... * n-1 * n ) * (1 * 2 * ... * n-1 * n)
     * f(n) = f(n-1) * 2n! / 2(n-1)! / n * n
     *
     */

    int n = 2;
    uint64_t fn = 2;
    while (n <= grid)
    {
        fn = fn * factorial(2 * n, 2 * (n - 1)) / (n * n);
        n++;
    }
    return fn;
}

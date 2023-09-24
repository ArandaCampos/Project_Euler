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

uint64_t sequence(int n)
{
    /*
     * f(1) = 2
     * f(n) = f(n-1) * (2n)! / [2(n-1)]! / n * n
     *
     */

    int i = 2;
    uint64_t fn = 2;
    while (i <= n)
    {
        fn = fn * factorial(2 * i, 2 * (i - 1)) / (i * i);
        i++;
    }
    return fn;
}

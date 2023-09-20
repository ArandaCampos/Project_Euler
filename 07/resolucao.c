#include <stdlib.h>
#include <stdio.h>

int position_prime(int);
int is_prime(int);

int main()
{

    printf("%d\n", position_prime(10001));
    return 0;
}

int is_prime(int n)
{
    int limit = (n - (n % 2)) / 2;

    if (n <= 1) return 0;

    for (int i = 2; i <= limit; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

int position_prime(int position)
{
    int count = 1, n = 2;
    while (count != position)
    {
        n++;
        if (is_prime(n)) count++;
    }
    return n;
}

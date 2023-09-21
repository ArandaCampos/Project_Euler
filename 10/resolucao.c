#include <stdio.h>

int is_prime(int);
long int sum_of_all_primes_bellow(int);

int main()
{
    printf("%ld", sum_of_all_primes_bellow(2000000));
    return 0;
}

int is_prime(int n)
{
    printf("%d\n", n);
    int limit = (n - (n % 2)) / 2;

    for (int i = 2; i <= limit; i++)
    {
        if (n % i == 0) return 0;
    }
    return n;
}

long int sum_of_all_primes_bellow(int x)
{
    long int sum = 2;
    int prime = 3;

    for (; prime <= x; prime ++) sum += is_prime(prime);

    return sum;
}

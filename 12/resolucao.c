#include <stdio.h>

long int pa(int, int, int);
long int highly_divisible_triangular(int);

int main ()
{
    printf("%ld", highly_divisible_triangular(500));
    return 0;
}


long int pa(int i0, int in, int n)
{
    return (i0 + in) * n / 2;
}

long int highly_divisible_triangular(int divisors)
{
    /*
     *  a % b == 0 →  b * c = a →  a % c == 0 | a, b, c, E N*
     */

    long int number = pa(1, divisors, divisors), count, limit, aux = divisors;

    while(count < divisors)
    {
        number = pa(1, aux, aux);
        limit = number, count = 0;
        for (long int i = 1; i < limit ; i++)
            if (number % i == 0){
                limit = number / i;
                count += 2;
            }
        if (count < divisors) aux ++;
    }
    return number;
}

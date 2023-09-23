#include <stdio.h>

unsigned long int longest_Collatz_sequence(unsigned long int);
unsigned long int chains_Collatz_sequence(unsigned long int);

int main()
{
    printf("%ld \n", longest_Collatz_sequence(1000000));
    return 0;
}

unsigned long int chains_Collatz_sequence(unsigned long int n)
{
    unsigned long int chains = 0;

    if(n < 0) return 0;

    while(n > 1)
    {
        if (n % 2 == 0) n = n / 2;
        else n = 3 * n + 1;
        chains++;
    }

    return chains;
}

unsigned long int longest_Collatz_sequence(unsigned long int n)
{
    unsigned long int number = 0, aux = 0, chains = 0;

    for (unsigned long int i = 1; i <= n; i++)
    {
        aux = chains_Collatz_sequence(i);
        if (aux > chains) chains = aux, number = i;
    }

    return number;
};

#include <stdio.h>
#include <stdlib.h>

typedef struct Fibonacci{
    unsigned long ultimate;
    unsigned long penultimate;
} tFibonacci;
typedef tFibonacci* pFibonacci;

int sum_even_valued_fibonacci(unsigned long);

int main()
{

    printf("%d\n", sum_even_valued_fibonacci(4000000));
    return 0;
}

int sum_even_valued_fibonacci(unsigned long max)
{
    unsigned long aux, sum = 0;
    pFibonacci sequence = (pFibonacci)malloc(sizeof(tFibonacci));

    sequence->penultimate = 1;
    sequence->ultimate = 1;

    for (int i = 1; i < max; i++)
    {
        aux = sequence->penultimate;
        sequence->penultimate = sequence->ultimate;
        sequence->ultimate = sequence->penultimate + aux;

        if (sequence->ultimate > max) break;
        if (sequence->ultimate % 2 == 0) sum += sequence->ultimate;
    }

    free(sequence);

    return sum;
}

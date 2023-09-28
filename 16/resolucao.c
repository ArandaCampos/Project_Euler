#include <stdio.h>
#include "bigint.h"

int main()
{
    pBigint x = insert(NULL, 1);

    for (int i = 0; i < 1000; i++) x = times(x, 2);

    printf("%d\n", sum_digits(x));

    free_bigint(x);

    return 0;
}

#include <stdio.h>
#include <math.h>

int sum_multiples_3_5_bellow();

int main(){
    printf("%d", sum_multiples_3_5_bellow(1000));
    return 0;
}

int sum_multiples_3_5_bellow(int max)
{
    int sum = 0;
    for (int i = 1; i < max; i++) {
        if (i % 3 == 0 || i % 5 == 0) sum += i;
    };

    return sum;
}

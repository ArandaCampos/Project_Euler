#include <stdio.h>

int how_many_letters(int);

int main()
{
    long int sum = 0;
    for (int i = 1; i <= 1000; i++) sum += how_many_letters(i);
    printf("Total: %ld\n", sum);
    return 0;
}

int how_many_letters(int n)
{
    if (n == 0) return 0;
    if (n < 20)
    {
        // one, two, six, ten
        if (n == 1 || n == 2 || n == 6 || n == 10 ) return 3;
        // four, five, nine
        else if (n == 4 || n == 5 || n == 9) return 4;
        // three, seven, eight
        else if (n == 3 || n == 7 || n == 8) return 5;
        // eleven, twelven, twenty
        else if (n == 11 || n == 12) return 6;
        // fifteen, sixteen,
        else if (n == 15 || n == 16) return 7;
        // thirteen, fourteen, eighteen, nineteen
        else if (n == 13 || n == 14 || n == 18 || n == 19) return 8;
        // seventeen
        else if ( n == 17 ) return 9;
    }
    else if (n < 100)
    {
        // forty, fifty, sixty
        if (n / 10 == 4 || n / 10 == 5 || n / 10 == 6) return 5 + how_many_letters(n % 10);
        // twenty, thirty, eighty, ninety
        else if (n / 10 == 2 || n / 10 == 3 || n / 10 == 8 || n / 10 == 9) return 6 + how_many_letters(n % 10);
        // seventy
        else if (n / 10 == 7) return 7 + how_many_letters(n % 10);
    }
    else if (n < 1000)
    {
        // one, two, six, ten (hundred or hundred and)
        if (n / 100 == 1 || n / 100 == 2 || n / 100 == 6 || n / 100 == 10 )
        {
            if (n % 100 == 0) return 10;
            else return 13 + how_many_letters(n % 100);
        }
        // four, five, nine (hundred or hundred and)
        else if (n / 100 == 4 || n / 100 == 5 || n / 100 == 9)
        {
            if (n % 100 == 0) return 11;
            else return 14 + how_many_letters(n % 100);
        }
        // three, seven, eight (hundred or hundred and)
        else if (n / 100 == 3 || n / 100 == 7 || n / 100 == 8)
        {
            if (n % 100 == 0) return 12;
            else return 15 + how_many_letters(n % 100);
        }
    }
    // one thousand
    else if( n == 1000 ) return 11;
    return 0;
}

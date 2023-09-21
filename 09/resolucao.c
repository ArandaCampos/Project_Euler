#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pythagorean (int x);

int main()
{

    printf("%.1f\n", pythagorean(1000));
    return 0;
}

float pythagorean(int x)
{
    /*

    a + b + c = x
    a² + b² = c²,     { a, b, c, x E N }

    a + b + sqrt(a² + b²) = x

    if a = 0;
    0 + b + sqrt(0 + b²) = 1000
    b + b = 1000
    b = 500

    So, 0 < a < b < 500

    */

    float a = 1.0, b = x / 2, c = 0.0;

    while (a + b + c != x && b > 0)
    {
        a = 1;
        b--;
        for (; a < b; a++)
        {
            c = sqrt(pow(a, 2) + pow(b, 2));
            if (a + b + c == x)break;
        }
    }
    return a * b * c;
}

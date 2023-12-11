#include <stdio.h>

int isLeapYear(int);
int fellOnTheFirstDay(int, int, int);

int main ()
{
    int q = 0;
    for (int i = 1901; i <= 2000; i++){
        q += isLeapYear(i);
    }
    printf("Anos = %d\n", q);
    printf("%d\n", fellOnTheFirstDay(1901, 2000, 0));
    return 0;
}

int isLeapYear(int year){
    // A v B = A v (C ^ D)
    // ¬A ^ ¬B = ¬A ^ (¬C v ¬D)
    if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) return 1;
    return 0;
}

int fellOnTheFirstDay(int yearStart, int yearFinish, int dayOfWeek)
{
    int n = 0;
    int year = 1900;
    int day = 1; // monday
    int months[] = {
        31 % 7,  // Jan
        28 % 7,  // Fev
        31 % 7,  // Mar
        30 % 7,  // Abr
        31 % 7,  // Mai
        30 % 7,  // Jun
        31 % 7,  // Jul
        31 % 7,  // Ago
        30 % 7,  // Set
        31 % 7,  // Out
        30 % 7,  // Nov
        31 % 7   // Dez
    };

    while (year < yearStart){
        if ( isLeapYear(year) ) day = (day + 2) % 7;
        else day = (day + 1) % 7;
        year++;
    }

    while (year <= yearFinish){
        for (int i = 0; i < 12; i++){
            if (day == dayOfWeek)
            {
                n++;
            }
            day += months[i];

            if ( isLeapYear(year) && i == 1 ){
                day += 1;
            }
            day = day % 7;
        }
        year++;
    }

    return n;
}

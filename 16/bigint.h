#ifndef INT1000_H
#define INT1000_H

    #include <stdlib.h>

    typedef struct Bigint{
        char digit;
        struct Bigint* next;
    } tBigint;
    typedef tBigint* pBigint;

    void free_bigint(pBigint);
    pBigint insert(pBigint, char);
    int sum(pBigint);
    pBigint times(pBigint, int);

#endif

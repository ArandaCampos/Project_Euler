#include "bigint.h"

void free_bigint(pBigint a)
{
    pBigint aux;
	if (a != NULL) aux = a->next; else return;

	free(a);
	free_bigint(aux);
}

pBigint insert(pBigint bigint, char n)
{
    pBigint new = (pBigint)malloc(sizeof(tBigint)), aux = bigint;
    new->digit = n;
    new->next = NULL;

    if(bigint == NULL) return new;

    while(aux->next != NULL) aux = aux->next;
    aux->next = new;

    return bigint;
}

int sum(pBigint a){
    int sum = 0;
    for(; a != NULL; a = a->next) sum += a->digit;

    return sum;
}

pBigint times(pBigint a, int b)
{
    pBigint aux = a ;
    int x = 0 , y = 0;
    if (a == NULL) return NULL;

    for(; aux != NULL; aux = aux->next)
    {
        x = (int)aux->digit * b + y;
        y = x / 10;
        aux->digit = x % 10;
    }
    if (y > 0) a = insert(a, y);

    return a;
}

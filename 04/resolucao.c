#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int x;
    struct List* next;
    struct List* before;
} tList;
typedef tList* pList;

int largest_palindrome();
int is_palindrome(int);
void free_list(pList);

int main()
{
    printf("%d\n", largest_palindrome());
    return 0;
}

void free_list(pList first)
{
    pList aux = NULL;
    while (first != NULL){
        aux = first;
        first = first->next;
        free(aux);
    }
}

int is_palindrome(int value)
{
    int count = 0;
    pList first = NULL, before = NULL, aux = NULL;

    first = (pList)malloc(sizeof(tList));
    first->next = NULL;

    aux = first;

    while (value > 0)
    {
        aux->x = value % 10;
        value = (value - (value % 10)) / 10;

        if (value > 0)
        {
            pList next = (pList)malloc(sizeof(tList));
            aux->next = next;
            next->before = aux;
            aux = aux->next;
            aux->next = NULL;
        }
        count += 1;
    }

    before = aux;
    aux = first;

    for (int i = 1; i < count ; i++, count-- )
    {
        if (first->x != before->x)
        {
            free_list(aux);
            return 0;
        }
        first = first->next;
        before = before->before;
    }
    free_list(aux);
    return 1;
}

int largest_palindrome()
{
    int x, y, palindrome = 0;
    for (x = 999; x >= 100; x--)
    {
        y = x;
        for (; y >= 100; y--)
        {
            if (x*y < palindrome && palindrome != 0) break;
            if (is_palindrome(x*y)) palindrome = x * y;
        }
    }
    return palindrome;
}

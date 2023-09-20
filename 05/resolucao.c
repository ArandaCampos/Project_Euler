#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int n;
    struct List* next;
} tList;

typedef tList* pList;

pList insert(pList, int);
void clear(pList);
int is_prime(int);
int get_primes(int);
long int smallest_multiple(pList, int);

int main()
{
    pList node = NULL;
    printf("%ld\n", smallest_multiple(node, 20));
    return 0;
}

pList insert(pList list, int value)
{
    pList node = (pList)malloc(sizeof(tList)), aux = NULL;
    node->n = value;
    node->next = NULL;

    // Lista vazia
    if (list == NULL) list = node;
    else
    {
        aux = list;
        // Insere no fim da fila
        while(aux->next != NULL) aux = aux->next;
    aux->next = node;
    }
    return list;
}

void clear(pList node)
{
    pList aux = NULL;
    while(node != NULL)
    {
        aux = node;
        node = node->next;
        free(aux);
    }
}

int is_prime(int n)
{
    int limit = (n - (n % 2)) / 2;
    if (n <= 1) return 0;
    for (int i = 2; i <= limit; i++) if (n % i == 0) return 0;
    return 1;
}

int get_primes(int n)
{
    int multiple = 1;
    for (int i = n; i > 0; i--) if (is_prime(i)) multiple *= i;
    return multiple;
}

long int smallest_multiple(pList node, int n)
{
    pList aux = NULL;
    int commum = get_primes(n), i = 1;
    long int smallest = 0;

    for (int j = 1; j <= n; j++)
    {
        if (commum % j != 0) node = insert(node, j);
    }

    while (smallest == 0)
    {
        aux = node;
        while(aux != NULL)
        {
            if ((commum * i) % aux->n != 0) break;
            aux = aux->next;
            if (aux == NULL) smallest = commum * i;
        }
        i++;
    }
    clear(node);

    return smallest;
}

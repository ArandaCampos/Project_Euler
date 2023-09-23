#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct List{
    unsigned long int number;
    struct List* next;
} tList;
typedef tList* pList;

pList insert_n(pList, unsigned long);
void free_list(pList);
pList load_data(FILE*, pList, int);
unsigned long long int sum(pList);

int main()
{
    pList list = NULL;

    FILE *fp;
    fp = fopen("data.txt", "r");

    list = load_data(fp, list, 10);
    printf("%lld\n", sum(list));

    free_list(list);
    fclose(fp);
    return 0;
}

pList insert_n(pList list, unsigned long n)
{
    pList new = (pList)malloc(sizeof(tList)), aux = list;
    new->number = n, new->next = NULL;

    if (list == NULL) return new;

    while(aux->next != NULL) aux = aux->next;

    aux->next = new;
    return list;
}

void free_list(pList list)
{
    pList aux;

	if (list != NULL) aux = list->next; else return;

	free(list);
	free_list(aux);
}

pList load_data(FILE* fp, pList list, int digits)
{
    unsigned long int n = 0;
    int i = digits;
    char c;

    while((c = getc(fp)) != EOF)
    {
        if (c == '\n')
        {
            list = insert_n(list, n);
            i = digits, n = 0;
        }
        else if (c >= 48 && c <= 57 && i >= 0){
            n += ((int)c - 48) * pow(10, i);
            i--;
        }
    }
    return list;
}

unsigned long long int sum(pList list)
{
    unsigned long long int sum;
    while(list != NULL) sum += list->number, list = list->next;
    while (sum > 10000000000) sum = sum / 10;
    return sum;
}

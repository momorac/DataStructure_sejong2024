#include <stdio.h>
#include <stdlib.h>

struct node
{
    int elem;
    struct node *next;
} typedef NODE;

void init(NODE *header)
{
    header = (NODE *)malloc(sizeof(NODE));
    header->next = NULL;
}

void add(NODE *set, int e)
{
    NODE *p = set;
    while (p->next != NULL)
    {
        if (p->elem == e)
            return;
        p = p->next;
    }

    p = set;
    while (p->elem < e && e < p->next->elem)
        p = p->next;
}

int main()
{

    NODE *setA, *setB;
    init(setA);
    init(setB);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int elem;
    struct node *next;
} typedef NODE;

int main()
{

    int m = 6, n = 3;
    NODE L[m];
    L[0].elem = 'O';
    L[0].next = &L[1];
    L[1].elem = 'R';
    L[1].next = &L[2];
    L[2].elem = 'A';
    L[2].next = &L[3];
    L[3].elem = 'N';
    L[3].next = &L[4];
    L[4].elem = 'G';
    L[4].next = &L[5];
    L[5].elem = 'E';
    L[5].next = NULL;

    NODE S[n];
    S[0].elem = 1;
    S[0].next = &S[1];
    S[1].elem = 4;
    S[1].next = &S[2];
    S[2].elem = 5;
    S[2].next = NULL;

    NODE *p = &L[0];
    NODE *q = &S[0];

    int idx = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q->elem - idx; j++)
            p = p->next;
        printf("%c ", p->elem);
        idx = q->elem;
        q = q->next;
    }

    return 0;
}
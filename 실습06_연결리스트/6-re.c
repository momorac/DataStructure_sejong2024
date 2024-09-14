#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

struct Node
{
    struct Node *prev;
    struct Node *next;
    char elem;
} typedef NODE;

NODE *head, *trailer;
int length;

void init(NODE *list);
void add(NODE *list, char c, int r);
void delete(NODE *list, int r);
void get(NODE *list, int r);
void print(NODE *list);

int main()
{
    int n;
    char c;
    int r;
    char command;

    NODE *list;
    init(list);

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &command);

        if (command == 'P')
        {
            print(list);
        }
        else if (command == 'D')
        {
            scanf("%d", &r);

            delete (list, r);
        }
        else if (command == 'A')
        {
            scanf("%d", &r);
            scanf(" %c", &c);

            add(list, c, r);
        }

        else if (command == 'G')
        {
            scanf("%d", &r);
            get(list, r);
        }
        getchar();
    }

    int i = 0;
    for (NODE *p = head; i < length; i++)
    {
        free(p);
        p = p->next;
    }

    return 0;
}

void init(NODE *list)
{
    head = (NODE *)malloc(sizeof(NODE));
    trailer = (NODE *)malloc(sizeof(NODE));

    head->next = trailer;
    trailer->prev = head;
    length = 0;
}

void add(NODE *list, char c, int r)
{
    if ((r < 1) || (r > length + 1))
    {
        printf("invalid position\n");
        return;
    }
    NODE *p = head;

    for (int i = 0; i < r; i++)
    {
        p = p->next;
    }
    // p: 추가할 자리 다음 노드

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->elem = c;

    newNode->next = p;
    newNode->prev = p->prev;
    p->prev->next = newNode;
    p->prev = newNode;
    length++;
}

void delete(NODE *list, int r)
{
    if ((r < 1) || (r >= length + 1))
    {
        printf("invalid position\n");
        return;
    }
    NODE *p = head;

    for (int i = 0; i < r; i++)
    {
        p = p->next;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    length--;
    free(p);
}

void get(NODE *list, int r)
{
    if ((r < 1) || (r >= length + 1))
    {
        printf("invalid position\n");
        return;
    }
    NODE *p = head;
    for (int i = 0; i < r; i++)
    {
        p = p->next;
    }
    printf("%c", p->elem);
}

void print(NODE *list)
{
    // 첫 번째 노드부터 시작
    NODE *p = head->next;
    while (p != trailer)
    {
        printf("%c", p->elem);
        p = p->next;
    }
    printf("\n");
}

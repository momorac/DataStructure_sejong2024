#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int elem;
    struct Node *next;
    struct Node *prev;
} typedef NODE;

struct Deque
{
    NODE *front;
    NODE *rear;
} typedef DEQUE;

// 데크 초기화 : front와 rear의 초기값은 -1
void init(DEQUE *deque)
{
    deque->front = NULL;
    deque->rear = NULL;
}

void add_front(DEQUE *deque, int e)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->elem = e;

    if (deque->front == NULL && deque->rear == NULL)
    { // 데크가 비었을 때
        deque->front = new;
        deque->rear = new;
        new->next = NULL;
        new->prev = NULL;
    }
    else
    {
        deque->front->prev = new;
        new->next = deque->front;
        new->prev = NULL;
        deque->front = new;
    }
}

void add_rear(DEQUE *deque, int e)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->elem = e;

    if (deque->front == NULL && deque->rear == NULL)
    { // 데크가 비었을 때
        deque->front = new;
        deque->rear = new;
        new->next = NULL;
        new->prev = NULL;
    }
    else
    {
        deque->rear->next = new;
        new->prev = deque->rear;
        new->next = NULL;
        deque->rear = new;
    }
}

int delete_front(DEQUE *deque)
{
    if (deque->front == NULL && deque->rear == NULL)
    { // 데크가 비었을 때
        printf("underflow");
        return -1;
    }
    else
    {
        NODE *tmp = deque->front;
        int e = tmp->elem;

        // 데크에 원소가 하나일 때
        if (deque->front == deque->rear)
        {
            deque->front = NULL;
            deque->rear = NULL;
        }
        else
        {
            deque->front = deque->front->next;
            deque->front->prev = NULL;
        }
        free(tmp);
        return e;
    }
}

int delete_rear(DEQUE *deque)
{
    if (deque->front == NULL && deque->rear == NULL)
    { // 데크가 비었을 때
        printf("underflow");
        return -1;
    }
    else
    {
        NODE *tmp = deque->rear;
        int e = tmp->elem;

        // 데크에 원소가 하나일 때
        if (deque->front == deque->rear)
        {
            deque->front = NULL;
            deque->rear = NULL;
        }
        else
        {
            deque->rear = deque->rear->prev;
            deque->rear->next = NULL;
        }
        free(tmp);
        return e;
    }
}

void print(DEQUE *deque)
{
    NODE *p = deque->front;
    while (p != NULL)
    {
        printf(" %d", p->elem);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    DEQUE deque;
    init(&deque);

    int n, tmp;
    scanf("%d", &n);

    char command[3];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", command);

        if (strcmp(command, "AF") == 0)
        {
            scanf("%d", &tmp);
            add_front(&deque, tmp);
        }
        else if (strcmp(command, "AR") == 0)
        {
            scanf("%d", &tmp);
            add_rear(&deque, tmp);
        }
        else if (strcmp(command, "DF") == 0)
        {
            tmp = delete_front(&deque);
            if (tmp < 0)
                break;
        }
        else if (strcmp(command, "DR") == 0)
        {
            tmp = delete_rear(&deque);
            if (tmp < 0)
                break;
        }
        else if (strcmp(command, "P") == 0)
        {
            print(&deque);
        }
    }

    return 0;
}
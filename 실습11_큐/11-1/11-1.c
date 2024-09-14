#include <stdio.h>
#include <stdlib.h>

int enqueue(int *queue, int n, int *front, int *rear, int elem)
{
    *rear += 1;
    *rear %= n;
    if (*rear == *front)
    {
        printf("overflow");
        return 0;
    }
    *(queue + *rear) = elem;
    return 1;
}
int dequeue(int *queue, int n, int *front, int *rear)
{
    if (*front == *rear)
    {
        printf("underflow");
        return -1;
    }
    *front += 1;
    *front %= n;
    int e = *(queue + *front);
    *(queue + *front) = 0;

    return e;
}

void print(int *queue, int n)
{
    for (int *p = queue; p < queue + n; p++)
    {
        printf(" %d", *p);
    }
    printf("\n");
}

int main()
{
    // 큐의 크기 입력받고 포인터 배열 동적할당하기
    int q, front, rear;
    scanf("%d", &q);

    int *queue = (int *)malloc(q * sizeof(int));
    front = 0, rear = 0;

    int n;
    scanf("%d", &n);

    char command;
    int tmp, elem;
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &command);

        if (command == 'I')
        {
            scanf("%d", &elem);
            tmp = enqueue(queue, q, &front, &rear, elem);
            if (tmp == 0)
            {
                print(queue, q);
                break;
            }
        }
        else if (command == 'D')
        {
            tmp = dequeue(queue, q, &front, &rear);
            if (tmp == -1)
                break;
        }
        else if (command == 'P')
        {
            print(queue, q);
        }
    }

    return 0;
}
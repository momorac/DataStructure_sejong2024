#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char stack[], char elem);
char pop(char stack[]);
char peek(char stack[]);
void duplicate(char stack[]);
void upRotate(char stack[], int n);
void downRotate(char stack[], int n);
void print(char stack[]);

int t = -1;
int n;

int main()
{
    scanf("%d", &n);

    // 크기 n의 문자 배열 stack 선언, 값 모두 0으로 초기화
    char stack[n];
    for (int i = 0; i < n; i++)
        stack[i] = 0;

    int round;
    scanf("%d", &round);

    char command[6], tmp;
    for (int i = 0; i < round; i++)
    {
        scanf("%s", command);

        if (strcmp(command, "POP") == 0)
        {
            pop(stack);
        }
        else if (strcmp(command, "PUSH") == 0)
        {
            getchar();
            scanf("%c", &tmp);
            push(stack, tmp);
        }
        else if (strcmp(command, "PEEK") == 0)
        {
            peek(stack);
        }
        else if (strcmp(command, "DUP") == 0)
        {
            duplicate(stack);
        }
        else if (strcmp(command, "UpR") == 0)
        {
            getchar();
            scanf("%c", &tmp);
            upRotate(stack, tmp);
        }
        else if (strcmp(command, "DownR") == 0)
        {
            getchar();
            scanf("%c", &tmp);
            downRotate(stack, tmp);
        }
        else if (strcmp(command, "PRINT") == 0)
        {
            print(stack);
        }
        else
        {
            printf("Wrong Input!\n");
        }
    }

    return 0;
}

void push(char stack[], char elem)
{
    if (t >= n - 1)
    {
        printf("Stack FULL\n");
        return;
    }

    t++;
    stack[t] = elem;
}

char pop(char stack[])
{
    if (t < 0)
    {
        printf("Stack Empty\n");
        return 0;
    }

    char popped = stack[t];
    stack[t] = 0;
    t--;
    return popped;
}

char peek(char stack[])
{
    if (t >= 0)
        return stack[t];
    else
    {
        printf("Stack Empty\n");
        return 0;
    }
}

void duplicate(char stack[])
{
    if (t >= n - 1)
    {
        printf("Stack FULL\n");
    }
    else
    {
        char dup = pop(stack);
        push(stack, dup);
        push(stack, dup);
    }
}

void print(char stack[])
{
    for (int i = t; i >= 0; i--)
    {
        printf("%c", stack[i]);
    }
    printf("\n");
}

void upRotate(char stack[], int n)
{
    if (t >= 0 && n > 0)
    {                         // 유효한 인덱스 범위 확인
        char temp = stack[t]; // top의 값을 임시 저장

        for (int i = t; i >= n; i--)
        { // n번째 원소까지만 회전
            stack[i] = stack[i - n];
        }

        for (int i = 0; i < n; i++)
        { // 처음 n개의 원소를 top으로 이동
            stack[i] = stack[t - n + 1 + i];
        }

        stack[n - 1] = temp; // 임시 저장한 값 삽입
    }
}

void downRotate(char stack[], int n)
{
    if (t >= 0 && n > 0)
    {                                 // 유효한 인덱스 범위 확인
        char temp = stack[t - n + 1]; // n번째 원소를 임시 저장

        for (int i = t - n + 1; i < t; i++)
        { // n번째 원소까지만 회전
            stack[i] = stack[i + 1];
        }

        stack[t] = temp; // 임시 저장한 값을 top으로 이동
    }
}

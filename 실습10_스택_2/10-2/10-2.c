#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n = 100;
int t = -1;

void push(int *stack, char elem)
{
    if (t < n)
    {
        t++;
        *(stack + t) = elem;
    }
    else
    {
        printf("Stack FULL\n");
    }
}

char pop(int *stack)
{
    char p;
    if (t < 0)
    {
        printf("Stack Empty\n");
        return 0;
    }
    p = *(stack + t);
    *(stack + t) = 0;
    t--;
    return p;
}

char duplicate(int *stack)
{
    char elem = pop(stack);
    push(stack, elem);
    push(stack, elem);
    return elem;
}

char peek(int *stack)
{
    return *(stack + t);
}

void print(int *stack, int t)
{
    int i;
    for (i = t; i >= 0; i--)
    {
        printf("%c", *(stack + i));
    }
    printf("\n");
}

int isOperand(char s)
{
    if (s >= '0' && s <= '9')
        return 1;
    else
        return 0;
}

int doOperator(char op, int a, int b)
{
    int result;
    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '/':
        result = a / b;
        break;
    case '*':
        result = a * b;
        break;
    }
    return result;
}

int main()
{
    int *stack;

    int count;
    scanf("%d", &count);

    char postfix[101];

    for (int i = 0; i < count; i++)
    {
        scanf("%s", postfix);

        // 피연산자 스택 초기화
        stack = (int *)malloc(n * sizeof(int));
        t = -1;

        int j = 0, a, b;
        char s;
        while (postfix[j] != '\0')
        {
            s = postfix[j];
            j++;

            if (isOperand(s))
            {
                push(stack, s - '0');
            }
            else
            {
                a = pop(stack);
                b = pop(stack);
                push(stack, doOperator(s, b, a));
            }
        }
        printf("%d", pop(stack));

        printf("\n");
        free(stack);
    }

    return 0;
}

/*
5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)
*/
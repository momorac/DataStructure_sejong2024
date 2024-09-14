#include <stdio.h>

int modulo(int a, int b)
{
    int result = a;
    while (result >= b)
    {
        result -= b;
    }
    return result;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", modulo(a, b));

    return 0;
}
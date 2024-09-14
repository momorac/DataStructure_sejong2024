#include <stdio.h>

void printInOrder(int n)
{
    if (n < 10)
    {
        printf("%d\n", n);
        return;
    }
    else
    {
        printf("%d\n", n % 10);
        printInOrder(n / 10);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    printInOrder(n);

    return 0;
}
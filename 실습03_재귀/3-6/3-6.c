#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    printf("%d", gcd(n1, n2));

    return 0;
}

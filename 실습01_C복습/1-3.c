#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{

    int n;
    scanf("%d", &n);

    int arr[50];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int a, b;
    scanf("%d %d", &a, &b);

    swap(arr + a, arr + b);

    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    return 0;
}
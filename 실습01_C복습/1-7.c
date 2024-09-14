#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr1[i] + arr2[n - 1 - i];
    }

    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr1[i]);
    }

    return 0;
}
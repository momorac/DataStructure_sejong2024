#include <stdio.h>

int max_recur(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        int max_rest = max_recur(arr, n - 1);
        return (arr[n - 1] > max_rest) ? arr[n - 1] : max_rest;
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int arr[20];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", max_recur(arr, n));

    return 0;
}
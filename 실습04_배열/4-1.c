#include <stdio.h>

void flipByRange(int arr[], int first, int last)
{
    int gap = last - first;
    gap = gap % 2 == 0 ? gap / 2 : gap / 2 + 1;

    for (int i = 0; i < gap; i++)
    {
        int tmp = arr[first + i];
        arr[first + i] = arr[last - i];
        arr[last - i] = tmp;
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int repeat;
    scanf("%d", &repeat);

    int first, last;
    for (int i = 0; i < repeat; i++)
    {
        scanf("%d %d", &first, &last);
        flipByRange(arr, first, last);
    }

    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    return 0;
}
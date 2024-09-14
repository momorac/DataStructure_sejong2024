#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    int num = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = num;
                num++;
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                arr[i][j] = num;
                num++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
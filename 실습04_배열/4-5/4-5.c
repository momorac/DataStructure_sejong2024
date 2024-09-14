#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // n*m배열 할당하고 값 모두 0으로 초기화
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            arr[i][j] = 0;
    }

    int i = 0, j = 0;

    for (int num = 1; num <= n * m; num++)
    {

        arr[i][j] = num;
        if (j == 0 || i == n - 1)
        {
            i = 0, j = 0;

            if (num == n * m)
                break;
            while (arr[i][j] != 0)
            {
                if (j < m - 1)
                    j++;
                else
                    i++;
            }
        }
        else
        {
            i++, j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
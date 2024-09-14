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

    // 방향: 우(1,0) / 좌(-1,0) / 상(0,1) / 하(0,-1)
    int direction[2] = {1, 0};

    int i = 0, j = 0;
    for (int num = 1; num <= n * m; num++)
    {

        if (direction[0] == 1 && direction[1] == 0)
        {
            if (j >= m || arr[i][j] != 0)
            {
                j--;
                i++;
                num--;
                direction[0] = 0, direction[1] = -1;
            }
            else
            {
                arr[i][j] = num;
                j++;
            }
        }
        else if (direction[0] == 0 && direction[1] == -1)
        {
            if (i >= n || arr[i][j] != 0)
            {
                i--;
                j--;
                num--;
                direction[0] = -1, direction[1] = 0;
            }
            else
            {
                arr[i][j] = num;
                i++;
            }
        }
        else if (direction[0] == -1 && direction[1] == 0)
        {
            if (j < 0 || arr[i][j] != 0)
            {
                j++;
                i--;
                num--;
                direction[0] = 0, direction[1] = 1;
            }
            else
            {
                arr[i][j] = num;
                j--;
            }
        }
        else if (direction[0] == 0 && direction[1] == 1)
        {
            if (i < 0 || arr[i][j] != 0)
            {
                i++;
                j++;
                num--;
                direction[0] = 1, direction[1] = 0;
            }
            else
            {
                arr[i][j] = num;
                i--;
            }
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
#include <stdio.h>
#include <stdlib.h>

int mostOnes(int **A, int n)
{
    int i = 0, j = 0, row = 0;

    while ((i < n) && (j < n))
    {
        if (A[i][j] == 0)
        {
            i += 1;
        }
        else
        {
            row = i;
            j += 1;
        }
    }

    return row;
}

int main()
{
    int n;
    scanf("%d", &n);

    int **A;

    A = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    }

    printf("%d", mostOnes(A, n));

    return 0;
}


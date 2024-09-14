#include <stdio.h>
#include <stdlib.h>

int *prefixAverages1(int *X, int n)
{
    float sum;
    int *A;

    A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        sum = 0;

        for (int j = 0; j <= i; j++)
        {
            sum += X[j];
        }
        sum /= i + 1;
        sum += 0.5;
        sum /= 1;
        A[i] = sum;
    }

    return A;
}

int *prefixAverages2(int *X, int n)
{

    float sum = 0;
    int *A;

    A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        sum += X[i];
        A[i] = (sum / (i + 1) + 0.5) / 1;
    }
    return A;
}

int main()
{
    int n;
    int *A;
    int *X;

    scanf("%d", &n);

    A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    X = prefixAverages1(A, n);

    for (int i = 0; i < n; i++)
        printf("%d ", X[i]);

    printf("\n");

    X = prefixAverages2(A, n);

    for (int i = 0; i < n; i++)
        printf("%d ", X[i]);

    return 0;
}
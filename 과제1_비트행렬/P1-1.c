#include <stdio.h>
#include <stdlib.h>

// A 배열에 포함된 1의 개수를 모두 세는 함수 (느린버전)
int countOnesButSlow(int **A, int n)
{
    int c = 0; // 1의 개수 count할 변수

    int i = 0, j = 0;

    // 배열 A의 모든 행에 대해서
    for (i = 0; i < n; i++)
    {
        j = 0;
        // 한 행에서 각 열의 값이 1일때까지 카운트 수행
        while ((j < n) & (A[i][j] == 1))
        {
            c++;
            j++;
        }
    }

    return c;
}

// A 배열에 포함된 1의 개수를 모두 세는 함수 (빠른버전)
int countOnes(int **A, int n)
{
    int c = 0; // 1의 개수 count할 변수

    int i, j;
    // 배열 A의 모든 행에 대해서
    for (int i = 0; i < n; i++)
    {
        // 행의 끝부터 시작해서 0이 아닐 때까지 개수 세기
        j = n - 1;
        while (j >= 0 && A[i][j] == 0)
        {
            j--;
        }
        // 1일 때의 j의 값을 c에 저장 (+1한 값으로)
        c += j + 1;
    }
    return c;
}

int main()
{
    // 배열의 크기 n 입력받기
    int n;
    scanf("%d", &n);

    // 2차원 포인터 배열 A 생성하고 동적할당하기
    int **A;
    A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    // A의 값 입력받기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    }

    // 함수의 계산 결과 출력
    printf("%d\n%d", countOnesButSlow(A, n), countOnes(A, n));

    return 0;
}

/*
1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0
1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/
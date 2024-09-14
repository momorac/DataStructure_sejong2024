#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // 배열의 크기 n 1~100 범위 내에서 무작위로 생성하기
    srand(time(NULL));
    int n;
    n = rand() % 6;

    printf("n : %d", n);

    // n개의 정수 무작위로 생성하기
    int preOnes, curOnes;
    preOnes = n;
    for (int i = 0; i < n; i++)
    {
        curOnes = rand() % preOnes;
        printf("%d\n", curOnes);

        preOnes = curOnes;
    }

    return 0;
}

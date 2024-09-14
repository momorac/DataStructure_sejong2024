#include <stdio.h>

void ABC(int *p, int k)
{
    int max_int = -999;
    int *max_p = NULL;

    for (int *pp = p + k; pp < p + 10; pp++)
    {
        if (*pp > max_int)
        {
            max_int = *pp;
            max_p = pp;
        }
    }

    int tmp = *(p + k);
    *(p + k) = *max_p;
    *max_p = tmp;
}

int main()
{

    // 입력되는 정수를 배열에 저장
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int k = 0; k < 9; k++)
    {
        ABC(arr, k);
    }

    for (int i = 0; i < 10; i++)
    {
        printf(" %d", arr[i]);
    }

    return 0;
}
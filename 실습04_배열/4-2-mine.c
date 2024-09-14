#include <stdio.h>
#include <stdlib.h>

// 리스트의 노트 구조체 선언
struct Node
{
    int num;
    int origin_num;
    struct Node *next;

} typedef NODE;

int main()
{
    // 리스트의 길이 n 입력받기
    int n;
    scanf("%d", &n);

    // n의 길이를 가지는 Node 포인터 배열 X 생성 후 동적할당하기
    NODE *X = (NODE *)malloc(n * sizeof(NODE));

    // 리스트 값 입력받기
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &X[i].num);
        X[i].origin_num = X[i].num;
    }

    int swap_count;
    scanf("%d", &swap_count);

    int *swap_key = (int *)malloc(swap_count * sizeof(int));
    for (int i = 0; i < swap_count; i++)
    {
        scanf("%d", &swap_key[i]);
    }

    for (int i = 0; i < swap_count - 1; i++)
    {
        X[swap_key[i]].next = &X[swap_key[i + 1]];
        X[swap_key[i]].next->num = X[swap_key[i]].origin_num;
    }

    for (int i = 0; i < n; i++)
    {
        printf(" %d", X[i].num);
    }

    free(swap_key);
    free(X);
    
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct list
{
    int data;
    int pre_data;
    struct list *next;
}typedef LIST;

int main()
{
    int N, rev_arr[101], rev_cnt;
    scanf("%d", &N);

    struct list *system = NULL;
    system = (struct list *)malloc(sizeof(struct list) * N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &system[i].data);
        system[i].pre_data = system[i].data;
    }

    scanf("%d", &rev_cnt);

    for (int j = 0; j < rev_cnt; j++)
        scanf("%d", &rev_arr[j]);
    // 3 8 0 9 3


    for (int j = 0; j < rev_cnt - 1; j++)
    {
        /*값 변경 알고리즘*/
        system[rev_arr[j]].next = &system[rev_arr[j + 1]];
        printf("changing...\n");
        printf("%d -> %d\n", system[rev_arr[j]].next->data, system[rev_arr[j]].pre_data);
        system[rev_arr[j]].next->data = system[rev_arr[j]].pre_data;
    }

    for (int i = 0; i < N; i++)
        printf("%d ", system[i].data);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[8];
    int kor;
    int eng;
    int math;
    double avr;
} typedef STD;

int main()
{
    int n;
    scanf("%d", &n);

    STD *stds = (STD *)malloc(n * sizeof(STD));

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", stds[i].name, &stds[i].kor, &stds[i].eng, &stds[i].math);
        stds[i].avr = ((double)stds[i].kor + (double)stds[i].eng + (double)stds[i].math) / 3;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s %.1f", stds[i].name, stds[i].avr);

        if (stds[i].kor >= 90 || stds[i].eng >= 90 || stds[i].math >= 90)
            printf(" GREAT");
        if (stds[i].kor < 70 || stds[i].eng < 70 || stds[i].math < 70)
            printf(" BAD");
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

struct student
{
    char name[10];
    int score;
} typedef STD;

int main()
{
    STD stds[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%s %d", stds[i].name, &stds[i].score);
    }

    double avr = 0;
    for (int i = 0; i < 5; i++)
    {
        avr += stds[i].score;
    }
    avr /= 5;

    for (int i = 0; i < 5; i++)
    {
        if (stds[i].score < avr)
            printf("%s\n", stds[i].name);
    }

    return 0;
}
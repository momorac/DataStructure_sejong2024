#include <stdio.h>

struct Time
{
    int hour;
    int minute;
    int second;
} typedef TIME;

int main()
{
    TIME t1, t2;

    scanf("%d %d %d", &t1.hour, &t1.minute, &t1.second);
    scanf("%d %d %d", &t2.hour, &t2.minute, &t2.second);

    int time_gap = (t2.hour * 3600 + t2.minute * 60 + t2.second) - (t1.hour * 3600 + t1.minute * 60 + t1.second);

    printf("%d %d %d", time_gap / 3600, time_gap % 3600 / 60, time_gap % 3600 % 60);

    return 0;
}
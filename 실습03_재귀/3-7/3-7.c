#include <stdio.h>
#include <string.h>

int searchChar(char *str, char target)
{
    if (*str == '\0')
        return 0;

    int count = *str == target ? 1 : 0;

    return count + searchChar(str + 1, target);
}

int main()
{

    char str[101];
    scanf("%s", str);

    char target;
    getchar();
    scanf("%c", &target);

    printf("%d", searchChar(str, target));

    return 0;
}
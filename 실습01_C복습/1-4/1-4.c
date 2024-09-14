#include <stdio.h>
#include <string.h>

int main()
{

    char str[100];
    scanf("%s", str);

    printf("%s\n", str);
    for (int i = 1; i < strlen(str); i++)
    {
        char tmp = str[0];
        for (int j = 0; j < strlen(str); j++)
        {
            str[j] = str[j + 1];
        }
        str[strlen(str)] = tmp;
        printf("%s\n", str);
    }

    return 0;
}
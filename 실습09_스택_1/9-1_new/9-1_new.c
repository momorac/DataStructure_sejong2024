#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void push(char *s, int *t, char elem)
{
    (*t)++;
    *(s + *t) = elem;
}
char pop(char *s, int *t)
{
    char elem;

    if (t == -1)
        return 0;

    elem = *(s + *t);
    *(s + *t) = 0;
    (*t)--;
    return elem;
}

int main()
{
    char str[1001] = {0};
    char s[1001] = {0};
    char *p;
    char tmp;
    int n = 0, flag = 1;
    int t = -1;

    gets(str);
    for (p = str; *p; p++)
    {
        if (*p == '(' || *p == '{' || *p == '[')
        {
            n++;
            push(s, &t, *p);
        }
        if (*p == ')' || *p == '}' || *p == ']')
        {
            n++;
            tmp = pop(s, &t);

            if ((tmp == '(' && *p != ')') || (tmp == '{' && *p != '}') || (tmp == '[' && *p != ']'))
                flag = 0;
        }
    }

    if (t != -1)
        flag = 0;

    if (flag)
        printf("OK_%d", n);
    else
        printf("Wrong_%d", n);

    return 0;
}
#include <stdio.h>

int strEnd(char *s, char *t);

int main(void)
{
    char s[] = "Koushik Bhat";
    char t[] = " Bhat";

    printf("%d", strEnd(s, t));

    return 0;
}

int strEnd(char *s, char *t)
{
    char *cpyt = t;
    char *cpys = s;
    int cpyLen = 0;

    if (s < t)
        return 0;

    while (*cpyt != '\0')
    {
        cpyt++;
        cpyLen++;
    }

    while (*cpys != '\0')
        cpys++;

    cpys -= cpyLen;
    cpyt = t;

    while ((*cpys == *cpyt) && *cpys != '\0' && *cpyt != '\0')
    {
        cpys++;
        cpyt++;
    }

    if (*cpyt == '\0')
        return 1;

    return 0;
}
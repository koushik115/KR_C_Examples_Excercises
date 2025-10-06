#include <stdio.h>

void strCat(char *s, char *t);

int main(void)
{
    char s[] = "Koushik";
    char t[] = " Bhat";

    strCat(s, t);

    printf("%s ", s);

    return 0;
}

void strCat(char *s, char *t)
{
    while (*s != '\0')
        s++;

    while (*s++ = *t++)
        ;
}

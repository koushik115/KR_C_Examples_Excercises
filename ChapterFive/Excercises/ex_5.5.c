#include <stdio.h>

void strnCpy(char *s, char *t, int n);
void strnCat(char *s, char *t, int n);
int strnCmp(char *s, char *t, int n);

int main(void)
{
    char s1[100] = {0};
    char t1[] = "Koushik";
    strnCpy(s1, t1, 3);
    printf("%s\n", s1);

    char s2[] = "Koushik";
    char t2[] = "Bhatkoushik";
    strnCat(s2, t2, 4);
    printf("%s\n", s2);

    return 0;
}

void strnCpy(char *s, char *t, int n)
{
    while ((*s = *t) && n > 0)
    {
        s++;
        t++;
        n--;
    }

    while (n-- > 0)
        *s = '\0';
}

void strnCat(char *s, char *t, int n)
{
    while (*s != '\0')
        s++;

    while (n-- > 0 && *t != '\0')
        *s++ = *t++;

    *s = '\0';
}

int strnCmp(char *s, char *t, int n)
{
    if (n == 0)
        return 0;

    for (; n > 0 && *s == *t; s++, t++, n--)
        ;

    if (n == 0)
        return 0;

    return *s - *t;
}
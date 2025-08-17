#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int expand(char s1[], char s2[]);

int main(void)
{
    char s1[MAXLINE] = "-abc";
    char s2[MAXLINE] = {0};

    expand(s1, s2);

    printf("%s", s2);
}

int expand(char s1[], char s2[])
{
    // Remove whitespace
    int i, j;
    int start = 0, end = 0;

    for (i = 0; s1[i] == ' ' || s1[i] == '\n' || s1[i] == '\t'; i++)
        ;

    if (s1[i] == '-')
        i++;

    if (s1[i] >= 'a' && s1[i] <= 'z')
    {
        start = s1[i];

        while (((s1[i] >= 'a' && s1[i] <= 'z') || s1[i] == '-') && s1[i] != '\0')
            i++;
        end = s1[--i];

        for (j = 0; start <= end; start++, j++)
            s2[j] = start;
    }

    s2[j] = '\0';

    return j;
}
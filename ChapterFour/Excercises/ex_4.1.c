#include <stdio.h>

#define MAXLINE 100

int getLine(char line[], int maxline);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void)
{
    char line[MAXLINE];
    int found = 0;

    while ((getLine(line, MAXLINE)) > 0)
    {
        if (strrindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    }

    return found;
}

int getLine(char line[], int maxline)
{
    int c, i;

    for (i = 0; ((c = getchar()) != EOF) && c != '\n' && --maxline > 0; i++)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}

int strrindex(char source[], char searchfor[])
{
    int i, j, k;
    int found = -1;

    for (i = 0; source[i] != '\0'; i++)
    {
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
            ;

        if (k > 0 && searchfor[k] == '\0')
            found = i;
    }

    return found;
}

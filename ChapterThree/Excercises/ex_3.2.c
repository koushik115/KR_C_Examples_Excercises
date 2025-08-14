#include <stdio.h>

void escape(char s[], char t[]);

int main(void)
{
    char stringOne[] = "Example\tQuestion";
    char stringTwo[100];

    escape(stringOne, stringTwo);
    printf("%s", stringTwo);
}

void escape(char s[], char t[])
{
    int i = 0, j = 0;

    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            i++;
            break;

        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            i++;
            break;

        default:
            t[j++] = s[i++];
            break;
        }
    }

    t[j] = '\0';
}

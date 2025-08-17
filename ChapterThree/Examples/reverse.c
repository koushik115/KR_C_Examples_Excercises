#include <stdio.h>
#include <string.h>

#define MAXLINE 100
void reverse(char s[]);

int main(void)
{
    char Str[MAXLINE] = "String";
    printf("Original: %s\n", Str);
    reverse(Str);
    printf("Reversed: %s\n", Str);

    return 0;
}

void reverse(char s[])
{
    int i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
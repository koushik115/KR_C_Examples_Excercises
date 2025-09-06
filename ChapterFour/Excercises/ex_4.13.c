#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j);

int main(void)
{
    char s[] = "Hello!";
    reverse(s, 0, strlen(s) - 1);

    printf("%s", s);

    return 0;
}

void reverse(char s[], int i, int j)
{
    if (i >= j)
        return;

    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++;
    j--;

    reverse(s, i, j);
}

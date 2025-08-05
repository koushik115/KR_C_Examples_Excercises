#include <stdio.h>
void squeeze(char s1[], char s2[]);

int main(void)
{
    char strOne[] = "Koushiik";
    char strTwo[] = "ik";
    squeeze(strOne, strTwo);
    printf("%s", strOne);
}

void squeeze(char s1[], char s2[])
{
    int i, j;
    int index = 0;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0' && (s1[i] != s2[j]); j++)
            ;
        if (s2[j] == '\0')
            s1[index++] = s1[i];
    }

    s1[index] = '\0';
}
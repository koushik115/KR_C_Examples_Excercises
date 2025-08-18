#include <stdio.h>
#include <string.h>

#define MAXLINE 100

const char hexnum[] = "0123456789ABCDEF";
void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    int base, num;
    char s[MAXLINE] = {0};
    printf("Enter the base you want to convert the decimal number into: ");
    scanf("%d", &base);
    printf("Enter a decimal number to convert into base %d: ", base);
    scanf("%d", &num);
    itob(num, s, base);
    printf("%s", s);
    return 0;
}

void itob(int n, char s[], int b)
{
    int i = 0;
    switch (b)
    {
    case 2:
        do
        {
            s[i++] = n % 2 + '0';
        } while ((n /= 2) > 0);

        s[i] = '\0';
        reverse(s);

        break;

    case 8:
        do
        {
            s[i++] = n % 8 + '0';
        } while ((n /= 8) > 0);

        s[i] = '\0';
        reverse(s);

        break;

    case 16:
        do
        {
            if ((n % 16) > 9 && (n % 16) < 16)
            {
                s[i++] = hexnum[n % 16];
            }
            else
            {
                s[i++] = n % 16 + '0';
            }
        } while ((n /= 16) > 0);

        s[i] = '\0';
        reverse(s);

        break;

    default:
        printf("Invalid command\n");
        break;
    }
}

void reverse(char s[])
{
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
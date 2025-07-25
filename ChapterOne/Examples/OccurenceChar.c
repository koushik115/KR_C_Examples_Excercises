#include <stdio.h>

int main(void) {
    int c = 0, i = 0, nwhite = 0, nother = 0;
    int ndigit[10] = {0};

    while((c = getchar()) != EOF) {
        if(c >= '0' && c <= '9')
            ndigit[c - '0']++;
        else if(c == ' ' || c == '\t' || c == '\n')
            nwhite++;
        else
            nother++;
    }

    printf("digits = ");
    for(i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", whitespace = %d, other = %d\n", nwhite, nother);
}
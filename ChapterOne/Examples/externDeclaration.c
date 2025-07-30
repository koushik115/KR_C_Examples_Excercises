#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getLine(void);
void copy(void);

int main(void) {
    int len;
    extern char longest[MAXLINE];
    extern int max;

    max = 0;

    while((len = getLine()) > 0) {
        if(len > max) {
            max = len;
            copy();
        }
    }

    if(max > 0) {
        printf("%s", longest);

    return 0;
    
    }
}

int getLine(void)
{
    int c, i;
    extern char line[MAXLINE];

    for(i = 0; i < MAXLINE - 1 && ((c = getchar()) != EOF) && c != '\n'; i++)
        line[i] = c;

    if(c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';

    return 0;
}

void copy(void) {
    int i;
    extern char line[MAXLINE], longest[MAXLINE];

    i = 0;
    while((longest[i] = line[i]) != '\0')
        i++;
}

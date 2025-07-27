#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxlen);
void copy(char from[], char to[]);

int main(void) {
    char line[MAXLINE] = {0}, longest[MAXLINE];
    int len = 0, max = 0;

    while((len = getLine(line, MAXLINE)) > 0) {
        if(len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if(max > 0) 
        printf("%s", longest);

    return 0;
}

int getLine(char line[], int maxlen) {
    int c, i;

    for(i = 0; i < MAXLINE - 1 && ((c = getchar()) != EOF) && c != '\n'; i++)
        line[i] = c;

    if(c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';
    return i;
}

void copy(char from[], char to[]) {
    int i;

    for(i = 0; from[i] != '\0'; i++)
        to[i] = from[i];

    to[i] = '\0';
}
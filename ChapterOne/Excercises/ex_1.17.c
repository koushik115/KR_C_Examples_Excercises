#include <stdio.h>

#define  MAXLINE    1000

int getLine(char line[], int maxline);

int main(void) {
    int len = 0;
    char line[MAXLINE] = {0};

    while((len = getLine(line, MAXLINE)) > 0) {
        if(len > 80) {
            printf("%s", line);
        }
    }
}

int getLine(char line[], int maxline) {
    int i, c;

    for(i = 0; i < maxline - 1 && ((c = getchar()) != EOF) && c != '\n'; i++)
        line[i] = c;

    if(c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';
    return i;
}
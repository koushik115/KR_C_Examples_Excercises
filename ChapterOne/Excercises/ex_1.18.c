#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);

int main(void) {
    char line[MAXLINE] = {0};
    int len;

    while((len = getLine(line, MAXLINE))) {
        if(len > 0) {
            printf("%s\n", line);
        }
    }
}

int getLine(char line[], int maxline) {
    int i, c;
    int lastNonWhitespaceIdx = -1;

    for(i = 0; i < maxline - 1 && ((c = getchar()) != EOF) && c != '\n'; i++) {
        if(c != ' ' && c != '\t') 
            lastNonWhitespaceIdx = i;
        line[i] = c;
    }

    if(c == '\n') {
        if(lastNonWhitespaceIdx >= 0)
            line[++lastNonWhitespaceIdx] = c;
    }

    if(lastNonWhitespaceIdx >= 0) {
        line[++lastNonWhitespaceIdx] = '\0';
        return lastNonWhitespaceIdx;
    } else {
        line[0] = '\0';
        return 0;
    }
}
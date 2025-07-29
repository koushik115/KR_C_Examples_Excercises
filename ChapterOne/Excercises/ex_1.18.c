#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], char whitespace[], int maxline);

int main(void) {
    char line[MAXLINE] = {0}, whitespace[MAXLINE] = {0};
    int len;

    while((len = getLine(line, MAXLINE))) {

    }
}

int getLine(char line[], char whitespace[], int maxline) {
    int i, c;

    for(i = 0; i < maxline - 1 && ((c = getchar()) != EOF) && c != '\n'; i++) {
        if()
    }
}
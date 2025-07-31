#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char line[]);

int main(void) {
    int len;
    char line[MAXLINE] = {0};

    while((len = getLine(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

int getLine(char line[], int maxline) {
    int c, i;

    for(i = 0; i < MAXLINE - 1 && ((c = getchar()) != EOF) && c != EOF; i++)
        line[i] = c;

    if(c == '\n')
        line[++i] = c;

    line[i] = '\0';

    return i;
}

void reverse(char line[]) {
    int i = 0, j = strlen(line) - 1;

    while(i < j) {
        char c = line[i];
        line[i] = line[j];
        line[j] = c;
        i++; j--;
    }

    }
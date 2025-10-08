#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readline(char *lineptr[], char buffer[], int maxlimit);
void writeline(char *lineptr[], int maxlimit);
void qsort(char *v[], int left, int right);

int main(void)
{
    int nlines = 0;
    char buffer[MAXLINES] = {0};

    nlines = 0;
    if ((nlines = readline(lineptr, buffer, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writeline(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input line is too big too sort!\n");
    }
}

#define MAXLEN 1000
int getLine(char *line, int maxlimit);

int readline(char *lineptr[], char buffer[], int maxlimit)
{
    int len, nlines;
    char line[MAXLEN] = {0};

    while ((len = getLine(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlimit)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(buffer, line);
            lineptr[nlines++] = buffer;
        }
    }
}

void writeline(char *lineptr[], int maxlimit)
{
    for (int i = 0; i < maxlimit; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, last++, i);
    }

    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

int getLine(char *line, int maxlimit)
{
    int c, i;

    i = 0;
    while (--maxlimit > MAXLEN && ((c = getchar()) != EOF) && c != '\n')
        line[i++] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
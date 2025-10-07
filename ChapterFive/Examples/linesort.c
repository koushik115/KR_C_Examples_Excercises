#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void)
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort!\n");
        return -1;
    }
}

#define MAXLEN 1000

int getLine(char *line, int maxlimit);
char *alloc(int size);

int readlines(char *lineptr[], int maxlines)
{
    int nlines, len;
    char line[MAXLEN], *p;

    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            printf("error: max limit reached or allocation failed!\n");
            return -1;
        }
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(char *lineptr[], int left, int right)
{
    int i, last;
    void swap(char *lineptr[], int i, int j);

    if (left >= right)
        return;

    swap(lineptr, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        swap(lineptr, left, (left + right) / 2);
        if (strcmp(lineptr[i], lineptr[left]) < 0)
        {
            swap(lineptr, ++last, i);
        }
    }

    swap(lineptr, left, last);
    qsort(lineptr, left, last - 1);
    qsort(lineptr, last + 1, right);
}

int getLine(char *line, int maxlimit)
{
    int c, i;

    i = 0;
    while (--maxlimit > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}

#define ALLOCSIZE 1000
char allocbuff[ALLOCSIZE];
char *allocp = allocbuff;

char *alloc(int size)
{
    if (allocbuff + ALLOCSIZE - allocp >= size)
    {
        allocp += size;
        return allocp - size;
    }

    return 0;
}

void swap(char *lineptr[], int i, int j)
{
    char *temp;
    temp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = temp;
}
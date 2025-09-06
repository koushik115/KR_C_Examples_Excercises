#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main(void)
{
    int usort[] = {7, 2, 1, 6, 8, 5, 3, 4};
    qsort(usort, 0, (sizeof(usort) / sizeof(usort[0])) - 1);
    for (int i = 0; i < (sizeof(usort) / sizeof(usort[0])) - 1; i++)
        printf(" %d", usort[i]);

    return 0;
}

void qsort(int v[], int left, int right)
{
    int i, last;

    if (left >= right)
    {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }

    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
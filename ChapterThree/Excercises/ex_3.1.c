#include <stdio.h>
int binsearch(int x, int v[], int n);

int main(void)
{
    int num[] = {1, 2, 3, 4, 5, 6, 7};
    printf("%d", binsearch(2, num, 7));

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (x == v[low] && n > low)
        return low;

    return -1;
}

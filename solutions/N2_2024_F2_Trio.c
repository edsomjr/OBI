#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
    int a = *((int *) x), b = *((int *) y);

    return a - b;
}

int lower_bound(const int *xs, int N, int x)
{
    int a = 0, b = N, res = N;

    while (a <= b)
    {
        int m = a + (b - a)/2;

        if (xs[m] >= x)
        {
            res = m;
            b = m - 1;
        } else
            a = m + 1;
    }

    return res;
}

int main()
{
    int N;
    scanf("%d", &N);

    int as[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &as[i]);

    qsort(as, N, sizeof(int), compare);

    int ans = 0;

    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j)
        {
            int x = as[i] + as[j];
            int k = lower_bound(as, N, x);
            ans += (k - (i + 1));
        }

    printf("%d\n", ans);

    return 0;
}


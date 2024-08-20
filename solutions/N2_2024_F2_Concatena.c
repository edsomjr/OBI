#include <stdio.h>

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);

    long long ps[N + 1];
    ps[0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        scanf("%lld", &ps[i]);
        ps[i] += ps[i - 1];
    }

    for (int i = 0; i < Q; ++i)
    {
        int L, R;
        scanf("%d %d", &L, &R);

        long long sum = ps[R] - ps[L - 1];
        long long ans = 11*(R - L)*sum;

        printf("%lld\n", ans);
    }

    return 0;
}

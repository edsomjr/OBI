// NEPS 2438 - Intervalo Distinto (https://neps.academy/br/exercise/2438)
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int is[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &is[i]);

    int found[100001];

    for (int i = 0; i < 100001; ++i)
        found[i] = 0;

    int ans = 0, L = 0, R = 0;

    while (L < N)
    {
        while (R < N && found[is[R]] == 0)
        {
            found[is[R]] = 1;
            ++R;
        }

        int size = R - L;

        if (size > ans)
            ans = size;

        found[is[L]] = 0;
        ++L;
    }

    printf("%d\n", ans);

    return 0;
}

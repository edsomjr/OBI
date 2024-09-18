#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int as[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &as[i]);

    int hist[N + 1];

    for (int i = 1; i <= N; ++i)
        hist[i] = 0;

    long long resposta = 0;
    int R = 0, diferentes = 0;

    for (int L = 0; L < N; ++L)
    {
        while (R < N && diferentes < K)
        {
            if (hist[as[R]] == 0)
                ++diferentes;

            hist[as[R]]++;
            R++;
        } 

        if (diferentes == K)
            resposta += (N - R) + 1;

        hist[as[L]]--;

        if (hist[as[L]] == 0)
            --diferentes;
    }

    printf("%lld\n", resposta);

    return 0;
}

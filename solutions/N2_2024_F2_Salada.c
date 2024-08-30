#include <stdio.h>

int main()
{
    int R, N;
    scanf("%d %d", &R, &N);

    int Ts[101], Ps[101];

    for (int i = 0; i <= 100; ++i)
        Ts[i] = 101;

    for (int i = 0; i <= 100; ++i)
        Ps[i] = 0;

    for (int i = 0; i < N; ++i)
    {
        int T, P;
        scanf("%d %d", &T, &P);

        if (P < Ts[T])
            Ts[T] = P;
    }
    
    for (int t = 1; t <= 100; ++t)
        if (Ts[t] < 101)
            ++Ps[Ts[t]];

    int frutas = 0;

    for (int p = 1; p <= 100; ++p)
        for (int i = 0; i < Ps[p]; ++i)
            if (R >= p)
            {
                ++frutas;
                R -= p;
            }

    printf("%d\n", frutas);

    return 0;
}

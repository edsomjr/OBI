#include <stdio.h>

int sabores[10000001];

int main()
{
    int N, S;
    scanf("%d %d", &N, &S);

    int xs[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &xs[i]);

    int resposta = 0, L = 0, R = 0;

    while (L < N)
    {
        while (R < N && sabores[xs[R]] == 0)
        {
            sabores[xs[R]] = 1;
            ++R;
        }

        if (R - L > resposta)
            resposta = R - L;

        sabores[xs[L]] = 0;
        ++L;
    }

    printf("%d\n", resposta);

    return 0;
}

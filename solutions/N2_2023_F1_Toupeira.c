// NEPS 2323 - Toupeira (https://neps.academy/br/exercise/2323)
#include <stdio.h>

#define MAX 1010

char A[MAX][MAX];

int main()
{
    int S, T;
    scanf("%d %d", &S, &T);

    while (T--)
    {
        int X, Y;
        scanf("%d %d", &X, &Y);

        A[X][Y] = A[Y][X] = 1;
    }

    int P;
    scanf("%d", &P);

    int resposta = 0;

    while (P--)
    {
        int N;
        scanf("%d", &N);

        int a;
        scanf("%d", &a);

        int ok = 1;

        while (--N)
        {
            int b;
            scanf("%d", &b);

            ok *= A[a][b];
            a = b;
        }

        resposta += ok;
    }

    printf("%d\n", resposta);

    return 0;
}

// NEPS 2317 - Chinelos (https://neps.academy/br/exercise/2317)
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int xs[N + 1];

    for (int i = 1; i <= N; ++i)
        scanf("%d", &xs[i]);

    int P;
    scanf("%d", &P);

    int vendas = 0;

    while (P--)
    {
        int I;
        scanf("%d", &I);

        if (xs[I] > 0)
        {
            ++vendas;
            --xs[I];
        }
    } 

    printf("%d\n", vendas);

    return 0;
}

// NEPS 2316 - Epidemia (https://neps.academy/br/exercise/2316)
#include <stdio.h>

int main()
{
    int N, R, P;
    scanf("%d %d %d", &N, &R, &P);

    int dias = 0, infectadas = N;

    while (N < P)
    {
        infectadas = R*infectadas;
        N += infectadas;
        ++dias;
    }

    printf("%d\n", dias);

    return 0;
}

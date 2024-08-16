// NEPS 2434 - Pizza da OBI (https://neps.academy/br/exercise/2434)
#include <stdio.h>

int main()
{
    int N, G, M;
    scanf("%d %d %d", &N, &G, &M);

    int resto = 8*G + 6*M - N;

    if (resto >= 0)
        printf("%d\n", resto);
    else
        printf("0\n");

    return 0;
}

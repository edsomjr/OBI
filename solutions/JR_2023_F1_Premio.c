// OBI 2023 - Nível Júnior - Fase 1: Prêmio (https://neps.academy/br/exercise/2313)
#include <stdio.h>

int main()
{
    int P, D, B, pontos;
    scanf("%d %d %d", &P, &D, &B);

    pontos = P + 2*D + 3*B;

    if (pontos >= 150)
        printf("B\n");
    else if (pontos >= 120)
        printf("D\n");
    else if (pontos >= 100)
        printf("P\n");
    else 
        printf("N\n");

    return 0;
}

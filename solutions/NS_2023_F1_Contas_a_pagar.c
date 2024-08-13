// OBI 2023 - Fase 1 - Nível 2: Contas a pagar (https://neps.academy/br/exercise/2321)
#include <stdio.h>

int main()
{
    int V, A, F, P, S;
    scanf("%d %d %d %d", &V, &A, &F, &P);

    S = A + F + P;

    if (V >= S)
        printf("3\n");      // Ele consegue pagar todas as contas
    else if (V >= A + F || V >= A + P || V >= F + P)
        printf("2\n");      // Ele consegue pagar apenas duas contas
    else if (V >= A || V >= F || V >= P)
        printf("1\n");      // Ele consegue pagar apenas uma conta
    else
        printf("0\n");      // Ele não consegue nenhuma conta

    return 0;
}

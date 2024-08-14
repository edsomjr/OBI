// NEPS 2322 - Leilão (https://neps.academy/br/exercise/2322)
#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    char vencedor[12];
    int maior = 0;

    for (int i = 0; i < N; ++i)
    {
        char nome[16];
        int valor;

        scanf("%s %d", nome, &valor);

        if (valor > maior)
        {
            maior = valor;
            strcpy(vencedor, nome);
        }
    }

    printf("%s\n", vencedor);
    printf("%d\n", maior);

    return 0;
}

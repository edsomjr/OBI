// NEPS 2715 - Placas de Carro (https://neps.academy/br/exercise/2715)
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char placa[11];
    scanf("%s", placa);

    int N = strlen(placa), resposta = 0;

    if (N == 7)
    {
        char temp = placa[4];
        placa[4] = placa[3];
        placa[3] = temp;

        resposta = 2;

        for (int i = 0; i < 4; ++i)
            if (!isupper(placa[i]))
                resposta = 0;

        for (int i = 4; i < 7; ++i)
            if (!isdigit(placa[i]))
                resposta = 0;
    } else if (N == 8)
    {
        resposta = 1;

        for (int i = 0; i < 3; ++i)
            if (!isupper(placa[i]))
                resposta = 0;

        if (placa[3] != '-')
            resposta = 0;

        for (int i = 5; i < 8; ++i)
            if (!isdigit(placa[i]))
                resposta = 0;
    }

    printf("%d\n", resposta);

    return 0;
}

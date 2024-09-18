#include <stdio.h>

int main()
{
    int X;
    scanf("%d", &X);

    int resposta;

    if (X == 1)
        resposta = 1;
    else if (X == 2)
        resposta = 2;
    else if (X == 3)
        resposta = 4;
    else if (X == 4)
        resposta = 5;
    else if (X == 5)
        resposta = 7;
    else if (X == 6)
        resposta = 13;
    else
        resposta = 13 + (X - 6)*6;

    printf("%d\n", resposta);

    return 0;
}

## Lençol

Há dois casos a serem considerados. O primeiro caso consiste em avaliar se é possível recortar o lençol a partir de apenas um dos dois pedaços de tecido. Se ambas as dimensões de um dos pedaços forem maiores ou iguais a $A$ e $B$, a resposta será `S`. Atenção: é preciso considerar uma possível rotação do pedaço, ou seja, se considerarmos o pedaço $A1 \times B1$, é preciso avaliar também $B1\times A1$.

No segundo caso é preciso costurar os dois pedaços antes de fazer o corte. Se fixarmos o primeiro pedaço na orientação $A1\times B1$, há quatro
costuras possíveis:

1. unir $A2\times B2$ à direita de $A1\times B1$;
1. unir $B2\times A2$ à direita de $A1\times B1$;
1. unir $A2\times B2$ acima de $A1\times B1$;
1. unir $B2\times A2$ acima de $A1\times B1$;

Ao costurar os dois pedaços, uma das dimensões se tornará a soma dos lados correspondentes e a outra dimensão poderá ter, no máximo, tamanho igual ao menor dos tamanhos entre os lados correspondentes. Por exemplo, na primeira costura, obteremos um pedaço de tecido com base igual a $A1 + A2$, e cuja altura será igual a $\min(B1, B2)$. 

Se algum dos quatro pedaços resultantes puder se recortado para formar o lençol, a resposta será `S`; caso contrário, a resposta será `N`. Esta solução tem complexidade $O(1)$.

<details>
    <summary>__Solução em C__:</summary>
 ```C
#include <stdio.h>

int ok(int b, int h, int A, int B)
{
    return (A <= b && B <= h) || (A <= h && B <= b);
}

int min(int a, int b)
{
    return a <= b ? a : b;
}

int main()
{
    int A1, B1, A2, B2, A, B;
    scanf("%d %d %d %d %d %d", &A1, &B1, &A2, &B2, &A, &B);

    if (ok(A1, B1, A, B) || ok(A2, B2, A, B) ||   // Uma folha é suficiente
        ok(A1 + A2, min(B1, B2), A, B) ||         // Primeira fixa, segunda à direita
        ok(A1 + B2, min(B1, A2), A, B) ||         // Primeira fixa, segunda à direita rotacionada
        ok(min(A1, A2), B1 + B2, A, B) ||         // Primeira fixa, segunda acima
        ok(min(A1, B2), B1 + A2, A, B))           // Primeira fixa, segunda acima rotacionada
    {                                                  
        printf("S\n");
    } else
    {
        printf("N\n");
    }

    return 0;
}
```
</details>

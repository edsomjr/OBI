## Lençol

Há dois casos a serem considerados. O primeiro caso consiste em avaliar se é possível recortar o lençol a partir de apenas um dos dois pedaços de tecido. Se ambas as dimensões de um dos pedaços forem maiores ou iguais a $A$ e $B$, a resposta será `S`. Atenção: é preciso considerar uma possível rotação do pedaço, ou seja, se considerarmos o pedaço $A_1 \times B_1$, é preciso avaliar também $B_1\times A_1$.

No segundo caso é preciso costurar os dois pedaços antes de fazer o corte. Se fixarmos o primeiro pedaço na orientação $A_1\times B_1$, há quatro
costuras possíveis:

1. unir $A_2\times B_2$ à direita de $A_1\times B_1$;
1. unir $B_2\times A_2$ à direita de $A_1\times B_1$;
1. unir $A_2\times B_2$ acima de $A_1\times B_1$;
1. unir $B_2\times A_2$ acima de $A_1\times B_1$;

Ao costurar os dois pedaços, uma das dimensões se tornará a soma dos lados correspondentes e a outra dimensão poderá ter, no máximo, tamanho igual ao menor dos tamanhos entre os lados correspondentes. Por exemplo, na primeira costura, obteremos um pedaço de tecido com base igual a $A_1 + A_2$, e cuja altura será igual a $\min(B_1, B_2)$. 

Se algum dos quatro pedaços resultantes puder se recortado para formar o lençol, a resposta será `S`; caso contrário, a resposta será `N`. Esta solução tem complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

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


<details>
    <summary><b>Solução em C++</b></summary>

```Cpp
#include <bits/stdc++.h>

using namespace std;

bool ok(int b, int h, int A, int B)
{
    return (A <= b and B <= h) or (A <= h and B <= b);
}

auto solve(int A1, int B1, int A2, int B2, int A, int B)
{
    return ok(A1, B1, A, B) or ok(A2, B2, A, B)   // Uma folha é suficiente
        or ok(A1 + A2, min(B1, B2), A, B)         // Primeira fixa, segunda à direita
        or ok(A1 + B2, min(B1, A2), A, B)         // Primeira fixa, segunda à direita rotacionada
        or ok(min(A1, A2), B1 + B2, A, B)         // Primeira fixa, segunda acima
        or ok(min(A1, B2), B1 + A2, A, B);        // Primeira fixa, segunda acima rotacionada
}

int main()
{
    int A1, B1, A2, B2, A, B;
    cin >> A1 >> B1 >> A2 >> B2 >> A >> B;

    cout << (solve(A1, B1, A2, B2, A, B) ? 'S' : 'N') << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
def ok(b, h, A, B):
    return (A <= b and B <= h) or (A <= h and B <= b)


def solve(A1, B1, A2, B2, A, B):
    return any([ok(A1, B1, A, B), ok(A2, B2, A, B),     # Uma folha é suficiente
        ok(A1 + A2, min(B1, B2), A, B),                 # Primeira fixa, segunda à direita
        ok(A1 + B2, min(B1, A2), A, B),                 # Primeira fixa, segunda à direita rotacionada
        ok(min(A1, A2), B1 + B2, A, B),                 # Primeira fixa, segunda acima
        ok(min(A1, B2), B1 + A2, A, B)])                # Primeira fixa, segunda acima rotacionada


if __name__ == '__main__':
    A1, B1, A2, B2, A, B = map(int, input().split())

    if solve(A1, B1, A2, B2, A, B):
        print('S')
    else:
        print('N')
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```Java
import java.util.Scanner;

public class Main
{
    private static boolean ok(int b, int h, int A, int B)
    {
        return ((A <= b) && (B <= h)) || ((A <= h) && (B <= b));
    }

    private static int min(int a, int b)
    {
        if (a <= b)
            return a;

        return b;
    }

    private static boolean solve(int A1, int B1, int A2, int B2, int A, int B)
    {
        return ok(A1, B1, A, B) || ok(A2, B2, A, B)   // Uma folha é suficiente
            || ok(A1 + A2, min(B1, B2), A, B)         // Primeira fixa, segunda à direita
            || ok(A1 + B2, min(B1, A2), A, B)         // Primeira fixa, segunda à direita rotacionada
            || ok(min(A1, A2), B1 + B2, A, B)         // Primeira fixa, segunda acima
            || ok(min(A1, B2), B1 + A2, A, B);        // Primeira fixa, segunda acima rotacionada
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        int A1 = scanner.nextInt();
        int B1 = scanner.nextInt();
        int A2 = scanner.nextInt();
        int B2 = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        if (solve(A1, B1, A2, B2, A, B))
        {
            System.out.println('S');
        } else
        {
            System.out.println('N');
        }
    }
}
```
</details>

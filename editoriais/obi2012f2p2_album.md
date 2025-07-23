## Álbum de fotos

O problema consiste em determinar se é possível colar ambas as fotos na página dada. Para determinar a solução, é preciso considerar quatro cenários possíveis:

1. colocar as duas fotos uma sobre a outra, ambas em modo retrato;
1. colocar as duas fotos uma sobre a outra, a primeira em modo retrato, a segunda em modo paisagem;
1. colocar as duas fotos uma ao lado da outra, ambas em modo retrato;
1. colocar as duas fotos uma ao lado da outra, a primeira em modo retrato, a segunda em modo paisagem.

Se $L_1, H_1$ são as dimensões da primeira foto, $L_2, H_2$ as dimensões da segunda foto e $X, Y$ as dimensões da página, os cenários acima podem ser traduzidas nas seguintes expressões, quando confrontados com a página disponível:

1. $\max(L_1, L_2)\leq X, H_1 + H_2\leq Y$;
1. $\max(L_1, H_2)\leq X, H_1 + L_2\leq Y$;
1. $L_1 + L_2\leq X, \max(H_1, H_2)\leq Y$;
1. $L_1 + H_2\leq X, \max(H_1, L_2)\leq Y$.

Estas condições não consideram uma possível rotação da página, então de fato há mais quatro condições a serem verificadas, trocando as posições de $X$ e $Y$ nas quatro já apresentadas. 

Se uma destas condições for verdadeira, a resposta será `S`; caso contrário, a resposta será `N`. Esta solução tem complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int fit(int A, int B, int H, int W)
{
    return (A <= H && B <= W) || (A <= W && B <= H);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int X, Y, L1, H1, L2, H2;
    scanf("%d %d %d %d %d %d", &X, &Y, &L1, &H1, &L2, &H2);
    
    if (fit(L1 + L2, max(H1, H2), X, Y) || fit(L1 + H2, max(H1, L2), X, Y) ||
        fit(H1 + L2, max(L1, H2), X, Y) || fit(H1 + H2, max(L1, L2), X, Y))
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

```cpp
#include <bits/stdc++.h>

using namespace std;

bool fit(int A, int B, int H, int W)
{
    return (A <= H and B <= W) or (A <= W and B <= H);
}

auto solve(int L1, int H1, int L2, int H2, int X, int Y)
{
    return fit(L1 + L2, max(H1, H2), X, Y) or
           fit(L1 + H2, max(H1, L2), X, Y) or
           fit(H1 + L2, max(L1, H2), X, Y) or
           fit(H1 + H2, max(L1, L2), X, Y) ? 'S' : 'N';
}

int main()
{
    int X, Y, L1, H1, L2, H2;
    cin >> X >> Y >> L1 >> H1 >> L2 >> H2;
    
    cout << solve(L1, H1, L2, H2, X, Y) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```python
def fit(A, B, H, W):
    return (A <= H and B <= W) or (A <= W and B <= H);


X, Y = map(int, input().split())
L1, H1 = map(int, input().split())
L2, H2 = map(int, input().split())

ok = fit(L1 + L2, max(H1, H2), X, Y) or fit(L1 + H2, max(H1, L2), X, Y) or fit(H1 + L2, max(L1, H2), X, Y) or fit(H1 + H2, max(L1, L2), X, Y)

if ok:
    print('S')
else:
    print('N')
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Scanner;

public class solution {
    public static boolean fit(int A, int B, int H, int W) {
        return (A <= H && B <= W) || (A <= W && B <= H);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int L1 = scanner.nextInt();
        int H1 = scanner.nextInt();
        int L2 = scanner.nextInt();
        int H2 = scanner.nextInt();

        if (fit(L1 + L2, Math.max(H1, H2), X, Y) || fit(L1 + H2, Math.max(H1, L2), X, Y) ||
            fit(H1 + L2, Math.max(L1, H2), X, Y) || fit(H1 + H2, Math.max(L1, L2), X, Y))
        {
            System.out.println("S");
        } else
        {
            System.out.println("N");
        }
    }
}
```
</details>

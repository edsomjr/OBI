## Festa Junina

Embora o problema posicione a escola $E$, a lojinha $L$ e o supermercado $S$ em uma reta, para a solução
do problema é útil imaginar que os três estabelecimentos estejam posicionados no espaço bidimensional.

A primeira observação é que não é eficiente voltar a escola antes de ir ao próximo estabelecimento 
(por exemplo, usar a rota $E\to S\to E\to L\to E$). Assim, devemos avaliar apenas duas rotas:
$E\to S\to L\to E$ e $E\to L\to S\to E$. Em ambos casos as rotas correspondem às arestas de um triângulo
cujos vértices seriam $E, L$ e $S$, de modo que as distâncias percorridas seriam as mesmas.
Logo a resposta do problema seria a soma dos tamanhos destas arestas.

O tamanho de cada aresta seria a diferença entre o maior e o menor valor dentre as duas variáveis
envolvidas. Para evitar o uso de uma condicional (`if`, operador ternário, etc), podemos usar a função
`abs()` da biblioteca `stdlib.h`, a qual calcula a diferença, em valor absoluto, entre duas variáveis
$x$ e $y$ (isto é, $|x - y|$). Assim, a resposta $R$ do problema será dada por
$$
R = |E - L| + |L - S| + |S - E|
$$

Esta solução tem complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int E, S, L;
    scanf("%d %d %d", &E, &S, &L);

    int ans = abs(E - S) + abs(S - L) + abs(L - E);

    printf("%d\n", ans);

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

auto solve(int E, int S, int L)
{
    return abs(E - S) + abs(S - L) + abs(L - E);
}

int main()
{
    int E, S, L;
    cin >> E >> S >> L;

    cout << solve(E, S, L) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
E = int(input())
S = int(input())
L = int(input())

ans = abs(E - S) + abs(S - L) + abs(L - E)

print(ans)
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```Java
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int E = scanner.nextInt();
        int S = scanner.nextInt();
        int L = scanner.nextInt();

        int ans = Math.abs(E - S) + Math.abs(S - L) + Math.abs(L - E);

        System.out.println(ans);
    }
}
```
</details>

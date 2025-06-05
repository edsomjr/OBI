## Frequência na aula

Há diferentes abordagens possíveis para este problema. A primeira delas é inicializar um contador com o valor zero e, para cada valor
$x\in [0,V]$, onde $V = \max\lbrace V_1, V_2, \ldots, V_N\rbrace$, confrontar cada um dos $N$ elementos da sequência  com $x$: caso exista um
índice $j$ tal que $x = V_j$, incremente o contador em uma unidade. Ao final do processo este contador será a resposta do problema.

Esta abordagem tem complexidade $O(NV)$ e, embora receba o veredito TLE, é suficiente para obter os 40 pontos que o caderno atribui a um 
conjuntos de testes onde $N, V\leq 10^3$ pois, com estas restrições, vale que $NV\leq 10^6$ (atualmente, no contexto de problemas de competição,
para evitar o TLE, o número aproximado do total de operações do algoritmo deve estar próximo de, no máximo, $10^8$).

Para linguagens que possuam, em sua biblioteca padrão, a implementação da estrutura de dados `set`, que abstrai o conceito matemático de
conjuntos, há uma abordagem bastante direta. Basta criar um `set` $s$ e inserir cada um dos elementos $V_i$ dados na entrada em $s$. 
A resposta do problema será dada pelo tamanho de $s$ (as soluções em C++ e Python implementam esta abordagem).

Esta segunda abordagem tem complexidade ou $O(N)$ ou $O(N\log N)$, dependendo do custo de inserção de um elemento no conjunto (que, por sua vez,
depende da implementação do `set` na linguagem, que pode ser feita por tabelas _hash_ ou por árvores auto-balanceadas).

Em linguagem que não contam com `set` em sua API padrão, é possível resolver o problema por meio uma variação da técnica de histograma. 
Crie um vetor $h$ com capacidade para armazenar, pelo menos, $10^6 + 1$ elementos (pois $10^6$ é o maior valor possível para um elemento $V_i$, segundo o texto do problema, e o termo $+1$ se deve ao fato de que vetores em $C$ são indexados a partir de 0), todos tendo zero como valor inicial. 
Para cada elemento $V_i$ dado
na entrada, faça $h[V_i] = 1$, sinalizando que ao menos um elemento da sequência tem valor igual a $V_i$. Deste modo, o vetor $h$ indica se um dado
valor estava ou não presente na entrada. A resposta $R$ do problema é dada então por

$$
R = \sum_{i=0}^{10^6}  h[i]
$$

Esta abordagem tem complexidade $O(V + N)$, onde o termo $V$ provém da criação e inicialização do vetor $h$. A solução em C apresentada abaixo
implementa esta abordagem.

Por fim, é possível resolver este problema ordenando a sequência $V_1, V_2, \ldots, V_N$ dada na entrada, obtendo uma sequência $U_1, U_2, \ldots,
U_N$ (é indiferente se ordenação é não-crescente ou não-decrescente). Após criar um contador $S$, com valor inicial igual a $1$, basta olhar
todos os elementos, a partir de $U_2$, comparando-os com os seus antecessores na sequência: se $U_{i} \neq U_{i - 1}$, então $U_i$ é um novo elemento,
não contabilizado ainda, de modo que $S$ deve ser incrementando em uma unidade. Após avaliar todos os elementos da sequência $U$, a resposta do 
problema será $S$.

Esta última abordagem tem complexidade $O(N\log N)$, por conta da ordenação. Ela foi implementada na solução em Java apresentada abaixo.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int hist[1000001];

int main()
{
    int N;
    scanf("%d", &N);

    while (N--)
    {
        int x;
        scanf("%d", &x);

        hist[x] = 1;
    }

    int ans = 0;

    for (int i = 0; i <= 1000000; ++i)
        ans += hist[i];

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

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    set<int> s;

    while (N--)
    {
        int x;
        cin >> x;

        s.emplace(x);
    }

    cout << s.size() << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
N = int(input())

s = set()

for _ in range(N):
    s.add(int(input()))

print(len(s))
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();

        int[] xs = new int[N];

        for (int i = 0; i < N; ++i) {
            xs[i] = scanner.nextInt();
        }

        Arrays.sort(xs);

        int ans = 1;

        for (int i = 1; i < N; ++i) {
            if (xs[i] != xs[i - 1]) {
                ans += 1;
            }
        }

        System.out.println(ans);
    }
}
```
</details>

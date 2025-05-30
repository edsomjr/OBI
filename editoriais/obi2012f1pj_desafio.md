## Desafio do maior número

Problema consiste em determinar o maior dentre os números apresentados na entrada. Uma solução direita consiste em inicializar uma variável
$r$ com o valor zero (pois os demais número válidos da entrada são todos maiores ou iguais a 1) e, a cada número lido $x$, verificar se
este número é maior do que o valor atual de $r$: em caso afirmativo, atribuir a $r$ o valor de $x$. Tal solução tem complexidade $O(N)$,
onde $N$ é a quantidade de números dados na entrada.

Há uma segunda solução, com uso de memória maior ($O(N)$, contra a memória $O(1)$ da solução anterior), porém com código potencialmente mais 
curto. Ela consiste em ler todos os inteiros
da entrada de uma só vez e utilizar uma função da API padrão da linguagem para extrair o máximo (em C++, a função `max_element()`, ou a 
função `max()` de Python). A complexidade de tempo de execução permanece $O(N)$ (no caso de Python, bastam duas linhas para a solução.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int x, ans = 0;

    while (scanf("%d", &x), x)
        if (x > ans)
            ans = x;

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
    cin.tie(NULL);

    vector<int> xs;
    int x;

    while (cin >> x, x)
        xs.emplace_back(x);

    cout << *max_element(xs.begin(), xs.end()) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
xs = map(int, input().split())
print(max(xs))
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int ans = 0;

        while (scanner.hasNext())
        {
            int x = scanner.nextInt();

            if (x == 0)
                break;

            ans = Math.max(ans, x);
        }

        System.out.println(ans);
    }
}
```
</details>

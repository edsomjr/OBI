## Dieta

Garfield pode ingerir, no máximo, $M$ calorias, e fará $N$ refeições. Em cada refeição ele consome
$P$ gramas de proteína, $G$ gramas de gordura e $C$ gramas de carboidratos. Usando a tabela 
calórica dada no texto do problema, após uma refeição Garfield ingere $4(P + C) + 9G$ calorias.

Assim, usando um laço de repetição (`for` ou `while`) para processar as refeições, é possível 
chegar à resposta de duas maneiras:
1. a cada refeição processada, o total $M$ deve ser atualizado, descontando as calorias ingeridas;
2. acumular o total de calorias ingeridas nas refeições, e ao final subtrair de $M$ este total.

Em ambas abordagens, a solução terá complexidade $O(N)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int ans = M;

    while (N--)
    {
        int P, G, C;
        scanf("%d %d %d", &P, &G, &C);

        ans -= 4*(P + C) + 9*G;
    }

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
using iii = tuple<int, int, int>;

auto solve(int M, const vector<iii>& xs)
{
    auto ans = M;

    for (auto [P, G, C]: xs)
        ans -= 4*(P + C) + 9*G;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<iii> xs(N);

    for (auto& [P, G, C] : xs)
        cin >> P >> G >> C;

    cout << solve(M, xs) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
N, M = map(int, input().split())
ans = M

for _ in range(N):
    P, G, C = map(int, input().split())
    ans -= 4*(P + C) + 9*G

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

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        int ans = M;

        for (int i = 0; i < N; ++i) {
            int P = scanner.nextInt();
            int G = scanner.nextInt();
            int C = scanner.nextInt();

            ans -= 4*(P + C) + 9*G;
        }

        System.out.println(ans);
    }
}
```
</details>

## Gráfico de Barras

Há duas abordagens possíveis para a solução deste problema. A primeira delas é desenhar o gráfico de
barras do topo à base, uma linha por vez, isto é, da linha $H$ até a linha $1$, onde 
$H = \max\lbrace X_1, X_2, \ldots, X_N\rbrace$.
Fixada uma linha $i$, o elemento $a_{ij}$ da $j$-ésima coluna será igual a $1$ se $X_j \geq i$, ou zero,
caso contrário. Esta solução tem complexidade $O(HN)$ e dispensa a criação explícita da matriz (veja 
a solução em C).

Na segunda abordagem a matriz é construída explicitamente. Alocada a matriz $A_{H\times N}$, é possível
preencher uma coluna por vez, da base ao topo, colocando $X_i$ dígitos $1$, de baixo para cima, na coluna
$i$. Após o preenchimento a matriz deve ser impressa, do topo à base. Esta solução também tem
complexidade $O(NH)$ (veja a solução em C++).

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int hs[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", hs + i);

    int H = 0;

    for (int i = 0; i < N; ++i)
        if (hs[i] > H)
            H = hs[i];

    for (int h = H; h >= 1; --h)
        for (int i = 0; i < N; ++i)
            printf("%d%c", hs[i] >= h ? 1 : 0, i == N - 1 ? '\n' : ' ');

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

auto solve(int N, int H, const vector<int>& hs)
{
    vector<vector<int>> ans(H, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
        for (int h = 0; h < hs[i]; ++h)
            ans[h][i] = 1;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> hs(N);

    for (auto& h : hs)
        cin >> h;

    auto H = *max_element(hs.begin(), hs.end());
    auto ans = solve(N, H, hs);

    for (int h = H - 1; h >= 0; --h)
        for (int i = 0; i < N; ++i)
            cout << ans[h][i] << (i + 1 == N ? '\n' : ' ');

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
N = int(input())
hs = list(map(int, input().split()))

H = max(hs)

for h in range(H, 0, -1):
    line = list(map(lambda x: str(int(x >= h)), hs))
    print(' '.join(line))
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```Java
import java.util.Scanner;
import java.util.Arrays;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] hs = new int[N];

        for (int i = 0; i < N; ++i)
            hs[i] = scanner.nextInt();

        int H = Arrays.stream(hs).max().getAsInt();

        for (int h = H; h >= 1; --h) {
            for (int i = 0; i < N; ++i)
            {
                if (i > 0) {
                    System.out.print(' ');
                }

                if (hs[i] >= h) {
                    System.out.print('1');
                } else {
                    System.out.print('0');
                }
            }

            System.out.println();
        }
    }
}
```
</details>

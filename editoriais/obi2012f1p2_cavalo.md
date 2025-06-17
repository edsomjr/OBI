## O Tabuleiro Esburacado

Este é um problema cuja solução demanda a simulação do passeio do cavalo. O cavalo está posicionado inicialmente no ponto $(4, 3)$ e deve ser
movimentando até $N$ vezes, parando a simulação caso ele caia em um buraco ou caso consiga se mover exatamente $N$ vezes. Cada um dos 8 
movimentos possíveis atualizam as coordenadas $x$ e $y$ de sua posição atual, de acordo com o seu identificador:

- `1`: $+1$ na coordenada $x$, $+2$ na coordenada $y$;
- `2`: $+2$ na coordenada $x$, $+1$ na coordenada $y$;
- `3`: $+2$ na coordenada $x$, $-1$ na coordenada $y$;
- `4`: $+1$ na coordenada $x$, $-2$ na coordenada $y$;
- `5`: $-1$ na coordenada $x$, $-2$ na coordenada $y$;
- `6`: $-2$ na coordenada $x$, $-1$ na coordenada $y$;
- `7`: $-2$ na coordenada $x$, $+1$ na coordenada $y$;
- `8`: $-1$ na coordenada $x$, $+2$ na coordenada $y$.

Após cada movimento, deve ser verificado se a nova posição coincide ou não com um dos quatro buracos.

A solução tem complexidade $O(N)$. Em linguagens que possuem, em sua biblioteca padrão, estruturas como pares, vetores, dicionários e conjuntos, a implementação pode ser reduzida; nas demais, uma cadeia de condicionais é suficiente. 

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int x = 4, y = 3, ans = 0;

    while (N--)
    {
        int M;
        scanf("%d", &M);

        ++ans;

        if (M == 1)
        {
            x += 1;
            y += 2;
        } else if (M == 2)
        {
            x += 2;
            y += 1;
        } else if (M == 3)
        {
            x += 2;
            y -= 1;
        } else if (M == 4)
        {
            x += 1;
            y -= 2;
        } else if (M == 5)
        {
            x -= 1;
            y -= 2;
        } else if (M == 6)
        {
            x -= 2;
            y -= 1;
        } else if (M == 7)
        {
            x -= 2;
            y += 1;
        } else
        {
            x -= 1;
            y += 2;
        }

        if ((x == 1 && y == 3) || (x == 2 && y == 3) || (x == 2 && y == 5) || (x == 5 && y == 4))
            break;
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
using ii = pair<int, int>;

const vector<ii> moves { { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 }, { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 } };
set<ii> holes { { 1, 3 }, { 2, 3 }, { 2, 5 }, { 5, 4 } };

auto solve(const vector<int>& ms)
{
    ii pos { 4, 3 };
    auto ans = 0;

    for (auto m : ms)
    {
        auto [dx, dy] = moves[--m];
        auto& [x, y] = pos;

        x += dx;
        y += dy;
        ++ans;

        if (holes.count(pos))
            break;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> ms(N);

    for (auto& m : ms)
        cin >> m;

    cout << solve(ms) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
def solve(ms):
    moves = [(1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-2, 1), (-1, 2)]
    holes = set([(1, 3), (2, 3), (2, 5), (5, 4)])
    pos = (4, 3)
    ans = 0

    for m in ms:
        dx, dy = moves[m - 1]
        x, y = pos
        pos = (x + dx, y + dy)
        ans += 1

        if pos in holes:
            break

    return ans


if __name__ == '__main__':
    N = int(input())
    ms = map(int, input().split())
    print(solve(ms))
```
</details>

## Placar do Jogo

Segundo a descrição do problema:

1. os gols marcados por Paulo e Camila aconteceram em momentos distintos; e
2. as sequências $p_1, p_2, \ldots, p_P$ e $c_1, c_2, \ldots, c_C$ foram dadas em ordem cronológica.

Assim, para resolver este problema é preciso atualizar o placar da partida (que inicialmente é `0x0`) a
cada gol. Há duas maneiras de se fazer esta atualização.

A primeira delas (solução em C) é manter dois ponteiros $i$ e $j$, inicialmente iguais a zero, indicando
as posições, nas sequências $p$ e $c$, dos próximos gols marcados por Paulo e Camila, respectivamente. Assim, enquanto $i < P$ ou $j < C$, é preciso determinar quem foi o próximo a marcar um gol:

1. se $i == P$ (isto é, Paulo já marcou todos os seus gols) ou se $j < C$ e $c[j] < p[i]$ (isto é, ambos ainda tem gols a marcar, mas Camila será a próxima), então o número de gols de Camila e o ponteiro $j$ devem ser incrementados;
2. caso contrário, foi Paulo quem marcou o próximo gol: seu total e o ponteiro $i$ devem ser incrementados.

A segunda abordagem possível (solução em C++) é criar um vetor auxiliar $v$, cujos elementos serão pares de elementos $(t, w)$, onde $t$ é o instante em que um gol foi marcado e $w$ indica quem marcou um gol. Após a ordenação de $v$, os gols estarão em ordem cronológica, independente do autor. Assim, basta fazer uma travessia no vetor $v$, atualizando o placar a partir da informação do autor de cada gol.

A primeira abordagem tem complexidade $O(P +C)$; a segunda tem complexidade $O((P + C)\log(P + C))$, por conta da ordenação.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int P;
    scanf("%d", &P);

    int ps[P];

    for (int i = 0; i < P; ++i)
        scanf("%d", &ps[i]);

    int C;
    scanf("%d", &C);

    int cs[C];

    for (int i = 0; i < C; ++i)
        scanf("%d", &cs[i]);

    int i = 0, j = 0, paulo = 0, camila = 0;

    printf("0 0\n");

    while (i < P || j < C)
    {
        if (i == P || (j < C && cs[j] < ps[i]))
        {
            ++camila;
            ++j;
        } else
        {
            ++paulo;
            ++i;
        } 

        printf("%d %d\n", paulo, camila);
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
using ii = pair<int, int>;

constexpr int PAULO = 0, CAMILA = 1;

vector<ii> solve(const vector<int>& ps, const vector<int>& cs)
{
    vector<ii> goals;

    for (auto p : ps)
        goals.emplace_back(p, PAULO);

    for (auto c : cs)
        goals.emplace_back(c, CAMILA);

    sort(goals.begin(), goals.end());

    int paulo = 0, camila = 0;
    vector<ii> ans { { 0, 0 } };

    for (auto [_, who] : goals)
    {
        paulo += 1 - who;
        camila += who;
        ans.emplace_back(paulo, camila);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int P;
    cin >> P;

    vector<int> ps(P);

    for (auto& p : ps)
        cin >> p;

    int C;
    cin >> C;

    vector<int> cs(C);

    for (auto& c : cs)
        cin >> c;

    auto ans = solve(ps, cs);

    for (auto [p, c] : ans)
        cout << p << ' ' << c << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
ps = list(map(int, input().split()))[1:]
cs = list(map(int, input().split()))[1:]

gs = list(zip(ps, [0]*len(ps)))
gs.extend(list(zip(cs, [1]*len(cs))))

ans = ['0 0']
paulo = 0
camila = 0

for _, who in sorted(gs):
    paulo += 1 - who
    camila += who
    ans.append(f'{paulo} {camila}')

print('\n'.join(ans))
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```Java
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int P = scanner.nextInt();
        int[] ps = new int[P];

        for (int i = 0; i < P; ++i)
            ps[i] = scanner.nextInt();

        int C = scanner.nextInt();
        int[] cs = new int[C];

        for (int i = 0; i < C; ++i)
            cs[i] = scanner.nextInt();

        int i = 0, j = 0, paulo = 0, camila = 0;

        System.out.println("0 0");

        while (i < P || j < C)
        {
            if (i == P || (j < C && cs[j] < ps[i]))
            {
                ++camila;
                ++j;
            } else
            {
                ++paulo;
                ++i;
            } 

            System.out.println(paulo + " " + camila);
        }
    }
}
```
</details>

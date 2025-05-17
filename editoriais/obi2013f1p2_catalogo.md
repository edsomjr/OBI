## Catálogo de Músicas

Uma possível solução para este problema contém várias etapas, cada uma associada a um subproblema.

A primeira delas é processar a entrada de modo a construir a árvore de diretórios e arquivos. Os nós desta árvores serão números inteiros não-negativos, com zero indicado a pasta raiz. Nesta etapa serão declaradas e preenchidas quatro estruturas, que armazenam informações para um nó $u$:

1. o vetor `leaf`, onde `leaf[u]` é igual a 1 se $u$ está associado ao nome de uma música; caso contrário (se está associado a um nome de diretório), `leaf[u] = 0`;
2. o vetor `len`, onde `len[u]` é o número de caracteres que compõe o nome do diretório ou nome da música associada ao nó $u$;
3. o vetor `parent`, onde `parent[u]` é o número que indica o nó pai de $u$. Se $u$ é a raiz, então `parent[0] = -1`, indicando que ele não tem pai na árvore; e
4. o vetor `adj`, onde `adj[u]` é um dicionário, onde cada chave é o nome do diretório ou nome da música de um de seus filhos $v$, sendo o $v$ o valor associado a chave.

Estas estruturas podem ser preenchidas iterativamente em um laço que lê cada um nos $N$ arquivos da entrada. Para cada arquivo, é preciso separar os diretórios do nome do arquivo (são separados pelo caractere `/`). Uma vez separados, inicia-se uma travessia no nó raiz ($u = 0$) e se confronta o nome do componente com o dicionário `adj[u]`: se o nome não estiver entre as chaves do dicionário, é preciso tomar as seguintes providências:

1. criar um novo nó $v$, com o menor inteiro positivo ainda não usado para representar um nó;
1. atualizar `leaf[v]`, indicado se $v$ está associado a um nome de diretório ou nome de arquivo;
1. indicar que $u$ é pai de $v$ (`parent[v] = u`);
1. registrar o tamanho do nome associado a $v$ no vetor `len`;
1. iniciar o dicionário `adj[v]`; e
1. atualizar o dicionário `adj[u]`, incluindo o nome como chave e $v$ como valor.

Após estas atualizações basta prosseguir no laço, atualizando `u` com o valor de `adj[u][nome]`. Esta primeira etapa tem complexidade $O(NS\log S)$, onde $S$ é o tamanho do maior caminho de arquivo dado na entrada.

A segunda etapa consiste em uma travessia em profundidade (DFS) na árvore de diretórios e arquivos, com o intuito de obter dois novos vetores:

1. `nodes`, onde `nodes[u]` indica o número de arquivos que podem ser acessados a partir de `u`;
1. `cost`, onde `cost[u]` é o custo da representação de todos os arquivos que estão na subárvore que tem `u` como raiz.

Ambos vetores são preenchidos recursivamente, por meio da travessia. O caso base acontece nas folhas: se `leaf[u] = 1`, então `nodes[u] = 1` e `cost[u] = len[u]`. Para um nó $u$ que não é folha, temos que

$$
    nodes[u] = \sum_{v\in adj[u], v\neq parent[u]} nodes[v],
$$

isto é, o número de nós folhas na subárvore cuja raiz é $u$ é dado pelo número de nós folhas de seus filhos. Já o custo será dado por

$$
    cost[u] = \sum_{v\in adj[u], v\neq parent[u]} cost[v] + \delta_0(leaf[v])\times nodes[v](len[v] + 1),
$$

onde $\delta_0(x) = 1$, se $x = 0$, ou zero, caso contrário. O custo é a soma dos custos de seus filhos e, caso $u$ não seja folha, cada caminho até uma folha deve ser prefixado pelo nome do diretório mais o caractere `/` (na soma cima, o tamanho deste prefixo é dado por $len[v] + 1$). Esta etapa tem complexidade $O(V)$, onde $V$ é o número de vértices  da árvore.

Por fim, a última etapa consiste em avaliar, para cada nó $u$ que não seja folha, qual seria o custo da representação de se usar $u$ como diretório raiz. Faça $v = u$ e seja $p$ o pai de $v$ na árvore (isto é, `p = parent[v]`). Inicialmente, o custo $c$ para $u$ é dado por $c =$ `cost[v]`. Agora, enquanto $v$ não for a raiz (nas convenções adotadas até o momento, se $p\neq -1$), o custo deve ser acrescido do custo do pai, subtraído do custo de $v$, onde deve ser descontado os prefixos dos caminhos que passam por $v$ (que, em `cost[p]`, são iguais a `len[v] + 1`) e acrescidos o prefixo `../` (cujo tamanho inicial é 3). Atualizado o custo, tanto $v$ quando $p$ devem ser atualizados: $v = p, p =$ `parent[v]`. Deve se também atualizar o tamanho do prefixo, acrescentando ao seu valor corrente 3 unidades. 

Como o problema garante que a altura da árvore é, no máximo, igual a 100, esta etapa final tem complexidade $O(V)$, com constante multiplicada por este fator 100.

<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

void nodes_and_cost(int u, int p, vector<int>& nodes, vector<int>& cost, const vector<map<string, int>>& adj, const vector<int>& leaf, const vector<int>& len)
{
    if (leaf[u])
    {
        nodes[u] = 1;
        cost[u] = len[u];
        return;
    }

    nodes[u] = 0;
    cost[u] = 0;

    for (auto [_, v] : adj[u])
    {
        if (v == p)
            continue;

        nodes_and_cost(v, u, nodes, cost, adj, leaf, len);
        nodes[u] += nodes[v];
        cost[u] += cost[v] + (leaf[v] ? 0 : nodes[v]*(len[v] + 1));
    }
}

auto solve(const vector<map<string, int>>& adj, const vector<int>& leaf, const vector<int>& len, const vector<int>& parent)
{
    int M = (int) adj.size();
    vector<int> nodes(M), cost(M);

    nodes_and_cost(0, -1, nodes, cost, adj, leaf, len);

    int ans = cost[0];

    for (int u = 1; u < M; ++u)
    {
        if (leaf[u])
            continue;

        auto total = cost[u], v = u, p = parent[v], prefix = 3;

        while (p != -1)
        {
            auto c = cost[p] - cost[v] - (len[v] + 1)*nodes[v];
            c += (nodes[p] - nodes[v])*prefix;

            total += c;
            prefix += 3;
            v = p;
            p = parent[v];
        }

        ans = min(ans, total);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<map<string, int>> adj(1);
    vector<int> leaf { 0 }, parent { -1 }, len { 0 };
    int next = 1;

    while (N--)
    {
        string filename;
        cin >> filename;

        istringstream iss(filename);
        string s;

        int u = 0, last = 0;

        while (getline(iss, s, '/'))
        {
            if (adj[u].count(s) == 0)
            {
                leaf.emplace_back(0);
                parent.emplace_back(u);
                len.emplace_back(s.size());
                adj.push_back({ });
                last = next;
                adj[u][s] = next++;
            } 

            u = adj[u][s];
        }

        leaf[last] = 1;
    }

    cout << solve(adj, leaf, len, parent) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```python
import sys

def nodes_and_cost(u, p, nodes, cost, adj, leaf, size, parent):
    if leaf[u]:
        nodes[u] = 1
        cost[u] = size[u]
        return

    nodes[u] = 0
    cost[u] = 0

    for v in adj[u].values():
        if v == p:
            continue

        nodes_and_cost(v, u, nodes, cost, adj, leaf, size, parent)
        nodes[u] += nodes[v]
        cost[u] += cost[v];

        if not leaf[v]:
            cost[u] += nodes[v]*(size[v] + 1)

def solve(adj, leaf, size, parent):
    M = len(adj)
    cost = [0]*M
    nodes = [0]*M

    nodes_and_cost(0, -1, nodes, cost, adj, leaf, size, parent)

    ans = cost[0]

    for u in range(1, M):
        if leaf[u]:
            continue

        total = cost[u]
        v = u
        p = parent[v]
        prefix = 3;

        while p != -1:
            c = cost[p] - cost[v] - (size[v] + 1)*nodes[v]
            c += (nodes[p] - nodes[v])*prefix

            total += c
            prefix += 3
            v = p
            p = parent[v]

        ans = min(ans, total)

    return ans


if __name__ == '__main__':

    N = int(input())
    nxt = 1

    parent = [-1]
    leaf = [0]
    size = [0]
    adj = [{}]

    for _ in range(N):
        tokens = input().strip().split('/')
        u = 0
        last = 0

        for token in tokens:
            if token not in adj[u]:
                leaf.append(0);
                parent.append(u);
                size.append(len(token))
                adj.append({ });
                adj[u][token] = nxt;
                last = nxt;
                nxt += 1

            u = adj[u][token]

        leaf[last] = 1

    print(solve(adj, leaf, size, parent))
```
</details>


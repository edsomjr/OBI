## Volume da TV

A solução do problema consiste em simular as ações de Bruno. Sendo $V$ o volume inicial da TV, Bruno ou aumenta ($a_i > 0$) ou diminui ($a_i < 0$) o volume da TV. Desse modo, a operação básica é o incremento
do volume atual em $a_i$ unidades. Porém, dois cuidados devem ser tomados:

1. o volume não pode exceder 100 unidades;
2. o valor mínimo para o volume é igual a zero.

Como são $T$ ações, esta solução tem complexidade $O(T)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int V, T;
    scanf("%d %d", &V, &T);

    while (T--)
    {
        int A;
        scanf("%d", &A);

        V += A;

        if (V > 100)
            V = 100;

        if (V < 0)
            V = 0;
    }

    printf("%d\n", V);

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

auto solve(int V, const vector<int>& as)
{
    for (auto a : as)
        V = max(0, min(V + a, 100));

    return V;
}

int main()
{
    ios::sync_with_stdio(false);

    int V, T;
    cin >> V >> T;

    vector<int> as(T);

    for (auto& a : as)
        cin >> a;

    cout << solve(V, as) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
V, T = map(int, input().split())
As = map(int, input().split())

for A in As:
    V = max(0, min(V + A, 100))

print(V)
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int V = scanner.nextInt();
        int T = scanner.nextInt();

        for (int i = 0; i < T; ++i) {
            int A = scanner.nextInt();

            V += A;

            if (V > 100)
                V = 100;

            if (V < 0)
                V = 0;
        }

        System.out.println(V);
    }
}
```
</details>

## Busca na Internet

O problema consiste em determinar quantas pessoas clicarem no primeiro link. O inteiro $t$, dado na entrada, corresponde ao número de pessoas
que clicaram no link no terceiro dia. Segundo o texto do problema, este número é igual a metade das pessoas $s$ que clicaram no segundo dia,
isto é,

$$
t = \frac{s}{2},
$$

de modo que $s = 2t$. O número de pessoas que clicaram no segundo dia é a igual a metade do número de pessoas $p$ que clicaram no primeiro dia.
De forma análoga, temos

$$
s = \frac{p}{2}
$$

e

$$
p = 2s = 2(2t) = 4t
$$

Portanto a resposta do problema é dada por $4t$. Esta solução tem complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    printf("%d\n", t << 2);

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
    int t;
    cin >> t;

    cout << 4*t << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
t = int(input())
print(4*t)
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        System.out.println(4*t);
    }
}
```
</details>

## Café com Leite

A caneca do cliente tem capacidade de $C$ ml. Após Felipe preparar o café, os $C - D$ ml restantes
serão preenchidos com leite. Como o cliente deseja no mínimo $A$ e, no máximo, $B$ ml de leite,
a resposta do problema será `S` se $A\leq C - D\leq B$.

Esta solução em complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    int leite = C - D;

    if (A <= leite && leite <= B)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

auto solve(int A, int B, int C, int D)
{
    auto leite = C - D;

    return A <= leite and leite <= B ? 'S' : 'N';
}

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << solve(A, B, C, D) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
A = int(input())
B = int(input())
C = int(input())
D = int(input())

leite = C - D

if A <= leite and leite <= B:
    print('S')
else:
    print('N')
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```Java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int D = scanner.nextInt();

        int leite = C - D;

        if (A <= leite && leite <= B) {
            System.out.println("S");
        } else {
            System.out.println("N");
        }
    }
}
```
</details>

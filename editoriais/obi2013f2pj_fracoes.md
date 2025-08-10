## Soma de Frações

Uma maneira de se somar as frações $\frac{a}{b}$ e $\frac{c}{d}$ é observar que o produto $bd$ é um candidato a denominador comum (não necessariamente menor). Assim,

$$
\frac{a}{b} + \frac{c}{d} = \frac{ad + bc}{bd}
$$

A fração resultante não é, necessariamente, irredutível, de modo que é necessário computar o máximo divisor comum $g$ entre $ad + bc$ e $bd$. A fração irredutível, que será a resposta do problema, será dada por

$$
\frac{p}{q} = \frac{\frac{ad + bc}{g}}{\frac{bd}{g}}
$$

Esta solução tem complexidade $O(\log M)$, onde $M = \max(ad + bc, bd)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int p = a*d + b*c;
    int q = b*d;
    int g = gcd(p, q);

    printf("%d %d\n", p/g, q/g);

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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int p = a*d + b*c;
    int q = b*d;
    int g = gcd(p, q);

    cout << p/g << ' ' << q/g << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
from math import gcd

a, b, c, d = map(int, input().split())

p = a*d + b*c
q = b*d
g = gcd(p, q)

print(f'{p//g} {q//g}')
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Scanner;
import java.math.BigInteger;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        BigInteger p = BigInteger.valueOf(a*d + b*c);
        BigInteger q = BigInteger.valueOf(b*d);
        BigInteger g = p.gcd(q);

        p = p.divide(g);
        q = q.divide(g);

        System.out.println(p.toString() + " " + q.toString());
    }
}
```
</details>

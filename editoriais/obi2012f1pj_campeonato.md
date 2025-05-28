## Campeonato

Para determinar o vencedor do campeonato, primeiramente é preciso determinar o número de pontos que cada clube obteve no campeonato. Segundo
o texto do problema, temos $C_p = 3\times C_v + C_e$ e $F_p = 3\times F_v + F_e$. Agora, há apenas 3 cenários possíveis:

1. se o Cormengo obteve mais pontos ou, caso ambos clubes tenham mesmo número de pontos, mas ele obteve maior saldo de gols, Cormengo será o campeão e a saída será igual a '`C`'. Em notação matemática, $C_p > F_p$ ou $C_p = F_p$ e $C_s > F_s$;
2. de forma análoga, Flaminthians será campeão se $F_P > C_p$ ou $F_p = C_p$ e $F_s > F_e$ e a saída será '`F`'; ou
3. o campeonato termina empatado, com saída igual a '`=`'.

Os três cenários podem ser determinados por uma sequência de `if-else`. Em C++ é possível fazer as comparações simultaneamente, se forem
utilizados pares para representar os pontos e o saldo de gols de cada time.

Esta solução tem complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int Cv, Ce, Cs, Fv, Fe, Fs;
    scanf("%d %d %d %d %d %d", &Cv, &Ce, &Cs, &Fv, &Fe, &Fs);

    int C = 3*Cv + Ce, F = 3*Fv + Fe;

    if (C > F || (C == F && Cs > Fs))
        printf("C\n");
    else if (F > C || (C == F && Fs > Cs))
        printf("F\n");
    else
        printf("=\n");

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

int main()
{
    ios::sync_with_stdio(false);

    int Cv, Ce, Cs, Fv, Fe, Fs;
    cin >> Cv >> Ce >> Cs >> Fv >> Fe >> Fs;

    ii C(3*Cv + Ce, Cs), F(3*Fv + Fe, Fs);

    cout << (C > F ? 'C' : (F > C ? 'F' : '=')) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
Cv, Ce, Cs, Fv, Fe, Fs = map(int, input().split())

C = 3*Cv + Ce
F = 3*Fv + Fe

if C > F or (C == F and Cs > Fs):
    print("C")
elif F > C or (C == F and Fs > Cs):
    print("F");
else:
    print("=")
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int Cv = scanner.nextInt();
        int Ce = scanner.nextInt();
        int Cs = scanner.nextInt();

        int Fv = scanner.nextInt();
        int Fe = scanner.nextInt();
        int Fs = scanner.nextInt();

        int C = 3*Cv + Ce;
        int F = 3*Fv + Fe;

        if (C > F || (C == F && Cs > Fs))
            System.out.println("C");
        else if (F > C || (C == F && Fs > Cs))
            System.out.println("F");
        else
            System.out.println("=");
    }
}
```
</details>

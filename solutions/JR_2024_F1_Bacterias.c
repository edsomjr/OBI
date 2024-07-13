// NEPS 2711 - Bactérias (https://neps.academy/br/exercise/2712)
#include <stdio.h>

int main()
{
    int N, P;
    scanf("%d %d", &N, &P);

    int dias = 0, bacterias = 1;

    while (bacterias * P <= N)
    {
        bacterias *= P;
        dias += 1;
    }

    printf("%d\n", dias);

    return 0;
}

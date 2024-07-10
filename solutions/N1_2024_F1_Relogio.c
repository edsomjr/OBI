// NEPS 2713 - Relógio (https://neps.academy/br/exercise/2713)
#include <stdio.h>

int main()
{
    int H, M, S, T;
    scanf("%d %d %d %d", &H, &M, &S, &T);

    int start = (3600*H + 60*M + S) + T;

    int s = start % 60;
    start /= 60;

    int m = start % 60;
    start /= 60;

    int h = start % 24;

    printf("%d\n%d\n%d\n", h, m, s);

    return 0;
}

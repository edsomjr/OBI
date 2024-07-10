// NEPS 2710 - Ogro (https://neps.academy/br/exercise/2710)
#include <stdio.h>

int main()
{
    int E, D;
    scanf("%d %d", &E, &D);

    if (E > D)
        printf("%d\n", E + D);
    else
        printf("%d\n", 2*(D - E));

    return 0;
}

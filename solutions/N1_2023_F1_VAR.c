// NEPS 2318: VAR (https://neps.academy/br/exercise/2318)
#include <stdio.h>

int main()
{
    int X, Y;
    scanf("%d %d", &X, &Y);

    if (-8 <= X && X <= 8 && 0 <= Y && Y <= 8)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}

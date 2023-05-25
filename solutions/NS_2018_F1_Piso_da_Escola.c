#include <stdio.h>

int main()
{
    int L, C;
    scanf("%d %d", &L, &C);

    int tipo1 = L*C + (L - 1)*(C - 1);
    int tipo2 = 2*(L - 1) + 2*(C - 1);

    printf("%d\n%d\n", tipo1, tipo2);
}

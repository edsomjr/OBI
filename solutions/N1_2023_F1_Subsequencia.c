// NEPS: Subsequência (https://neps.academy/br/exercise/2320)
#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    int xs[A], ys[B];

    for (int i = 0; i < A; ++i)
        scanf("%d", &xs[i]);

    for (int i = 0; i < B; ++i)
        scanf("%d", &ys[i]);

    for (int i = 0, k = 0; i < A; ++i)
    {
        if (ys[k] == xs[i])
            ++k;

        if (k == B)
        {
            printf("S\n");
            return 0;
        }
    }

    printf("N\n");

    return 0;
}

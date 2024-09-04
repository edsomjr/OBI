#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int copos = 0;

    while (N--)
    {
        int A, B;
        scanf("%d %d", &A, &B);

        if (A == 1 || B == 0)
            ++copos;
    }

    printf("%d\n", copos);

    return 0;
}

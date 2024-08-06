// NEPS 2319: Estoque (https://neps.academy/br/exercise/2319)
#include <stdio.h>

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);

    int A[M + 1][N + 1];

    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", &A[i][j]);

    int P;
    scanf("%d", &P);

    int resposta = 0;

    for (int k = 0; k < P; ++k)
    {
        int i, j;
        scanf("%d %d", &i, &j);

        if (A[i][j] > 0)
        {
            ++resposta;
            --A[i][j];
        }
    } 
 
    printf("%d\n", resposta);

    return 0;
}

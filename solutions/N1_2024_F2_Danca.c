#include <stdio.h>

int main()
{
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);

    int linhas[N], colunas[M];

    for (int i = 0; i < N; ++i)
        linhas[i] = i;

    for (int j = 0; j < M; ++j)
        colunas[j] = j;

    for (int i = 0; i < P; ++i)
    {
        char O[2];
        int A, B;

        scanf("%s %d %d", O, &A, &B);
        --A;
        --B;

        if (O[0] == 'L')
        {
            int temp = linhas[A];
            linhas[A] = linhas[B];
            linhas[B] = temp;
        } else
        {
            int temp = colunas[A];
            colunas[A] = colunas[B];
            colunas[B] = temp;
        }
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            printf("%d%c", colunas[j] + M*linhas[i] + 1, j + 1 == M ? '\n' : ' ');

    return 0;
}

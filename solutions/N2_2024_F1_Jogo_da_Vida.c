// NEPS 2714 - Jogo da Vida (https://neps.academy/br/exercise/2714)
#include <stdio.h>

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);

    char A[N][N + 1], B[N][N + 1];

    for (int i = 0; i < N; ++i)
        scanf("%s", A[i]);

    for (int i = 0; i < Q; ++i)
    {
        for (int x = 0; x < N; ++x)
            for (int y = 0; y < N; ++y)
            {
                int vizinhos = 0;

                for (int dx = -1; dx <= 1; ++dx)
                    for (int dy = -1; dy <= 1; ++dy)
                    {
                        if (dx == 0 && dy == 0)
                            continue;

                        int u = x + dx, v = y + dy;

                        if (0 <= u && u < N && 0 <= v && v < N && A[u][v] == '1')
                            ++vizinhos;
                    }

                if ((A[x][y] == '0' && vizinhos == 3) || (A[x][y] == '1' && 2 <= vizinhos && vizinhos <= 3))
                    B[x][y] = '1';
                else
                    B[x][y] = '0';
            }

        for (int x = 0; x < N; ++x)
            for (int y = 0; y < N; ++y)
                A[x][y] = B[x][y];
    }

    for (int i = 0; i < N; ++i)
        printf("%s\n", A[i]);

    return 0;
}

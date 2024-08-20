#include <stdio.h>
#include <string.h>

int main()
{
    int K, N;
    scanf("%d %d", &K, &N);

    char alfabeto[70], mensagem[1010];
    scanf("%s %s", alfabeto, mensagem);

    for (int i = 0; i < N; ++i)
    {
        int ok = 0;

        for (int j = 0; j < K; ++j)
        {
            if (mensagem[i] == alfabeto[j])
            {
                ok = 1;
                break;
            }
        }

        if (ok == 0)
        {
            printf("N\n");
            return 0;
        }
    }

    printf("S\n");

    return 0;
}

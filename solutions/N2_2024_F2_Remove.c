#include <stdio.h>

#define oo 1000000000

int main()
{
    int N;
    scanf("%d", &N);

    int rodadas[N + 1];
    rodadas[0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        int res = oo, x = i;

        while (x)
        {
            int d = x % 10;
            x /= 10;

            if (d > 0 && res > rodadas[i - d] + 1)
                res = rodadas[i - d] + 1;
        }

        rodadas[i] = res;
    }

    printf("%d\n", rodadas[N]);

    return 0;
}
        

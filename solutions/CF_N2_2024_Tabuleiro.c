#include <stdio.h>

int main()
{
    int N, MOD = 1000000007;
    scanf("%d", &N);

    long long maneiras[N + 1];
    maneiras[0] = 1;
    maneiras[1] = 1;
    maneiras[2] = 3;

    for (int i = 3; i <= N; ++i)
    {
        maneiras[i] = (maneiras[i - 1] + 2*maneiras[i - 2]) % MOD;
        maneiras[i] = (maneiras[i] + 2*maneiras[i - 3]) % MOD;
    }

    printf("%lld\n", maneiras[N]);

    return 0;
}

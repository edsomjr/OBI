#include <stdio.h>

int main()
{
    long long X, Y, Z, N;
    scanf("%lld %lld %lld %lld", &X, &Y, &Z, &N);

    printf("%lld\n", (X + Y + Z) % N);

    return 0;
}

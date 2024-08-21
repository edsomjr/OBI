#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int total = N * N * N;
    int _3s = 8;
    int _2s = 12*(N - 2);
    int _1s = 6*(N - 2)*(N - 2);
    int _0s = total - _1s - _2s - _3s;

    printf("%d\n%d\n%d\n%d\n", _0s, _1s, _2s, _3s);

    return 0;
}

#include <stdio.h>
#include <string.h>

int xs[110];

int main()
{
    memset(xs, 0, sizeof xs);

    int N, C, M;
    scanf("%d %d %d", &N, &C, &M);

    int i;

    for (i = 0; i < C; ++i)
    {
        int x;
        scanf("%d", &x);

        xs[x] = 1;
    } 

    for (i = 0; i < M; ++i)
    {
        int y;
        scanf("%d", &y);

        xs[y] = 0;
    } 

    int ans = 0;

    for (i = 0; i < 110; ++i)
        ans += xs[i];

    printf("%d\n", ans);

    return 0;
}

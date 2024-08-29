#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    char s[N];
    scanf("%s", s);

    int sala = 1;

    for (int i = 0; i < N; ++i)
    {
        if (s[i] == 'E')
            sala *= 2;
        else
            sala = 2*sala + 1;
    }

    printf("%d\n", sala);

    return 0;
}

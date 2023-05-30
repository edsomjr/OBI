#include <stdio.h>

int seq[510];

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%d", &seq[i]);  

    int res = 1;

    for (int a = 1; a <= N; ++a)
    {
        for (int b = 1; b <= N; ++b)
        {
            if (a == b)
                continue;

            int len = 0, next = a;

            for (int k = 0; k < N; ++k)
            {
                if (seq[k] == next)
                {
                    ++len;

                    next = a + b - next;
                }
            }

            if (len > res)
                res = len;
        } 
    }

    printf("%d\n", res);

    return 0;
}

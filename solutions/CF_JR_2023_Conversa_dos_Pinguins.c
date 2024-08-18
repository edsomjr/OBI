#include <stdio.h>
#include <string.h>

int main()
{
    char A[2], B[2];
    scanf("%s %s", A, B);

    double TA, TB;
    scanf("%lf %lf", &TA, &TB);

    if (strcmp(A, "F") == 0)
    {
        TA = (TA - 32)*5/9;
    }

    if (strcmp(B, "F") == 0)
    {
        TB = (TB - 32)*5/9;
    }

    if (TA < TB)
    {
        printf("A\n");
    } else
    {
        printf("B\n");
    }

    return 0;
}

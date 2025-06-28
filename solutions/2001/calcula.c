/* calcula.c  -  por Guilherme Ottoni */

#include <stdio.h>

main()
{
  int n, x, acc, i, teste=1;
  while (scanf("%d",&n) == 1 && n > 0)
  {
    acc = 0;
    for (i=0; i < n; i++)
    {
      scanf("%d",&x);
      acc += x;
    }
    printf("Teste %d\n%d\n\n",teste++,acc);
  }
  return 0;
}


/* meteoro.c   -  por Guilherme Ottoni */

#include <stdio.h>

main()
{
  int n, x, y, x1, x2, y1, y2, cont, teste=1, i;
  while (scanf("%d %d %d %d",&x1,&y1,&x2,&y2) == 4 && x1+y1+x2+y2 > 0)
  {
    scanf("%d",&n);
    cont=0;
    for (i=0; i < n; i++)
    {
      scanf("%d %d",&x,&y);
      if (x1 <= x && x <= x2 && y1 >= y && y >= y2)
        cont++;
    }
    printf("Teste %d\n%d\n\n",teste++,cont);
  }
}



/* domino.c   -  por Guilherme Ottoni */

#include <stdio.h>
#include <string.h>

int grafo[7][7];
int marc[7], grau[7];

int bp(int p)
{
  int q;
  marc[p] = 1;
  for (q=0; q < 7; q++)
    if (grafo[p][q] && !marc[q])
      bp(q);
}

int grafo_conexo(void)
{
  int p;
  memset(marc,0,sizeof(marc));
  for (p=0; p < 7 && grau[p] == 0; p++);
  bp(p);
  for (p=0; p < 7; p++)
    if (grau[p] > 0 && !marc[p])
      return 0;
  return 1;    
}

main()
{
  int n, p, x, y, n_impares, teste=1;

  while (scanf("%d",&n) == 1 && n > 0)
  {
    memset(grau,0,sizeof(grau));
    memset(grafo,0,sizeof(grafo));
    for (p=0; p < n; p++)
    {
      scanf("%d %d",&x,&y);
      grau[x]++;
      grau[y]++;
      grafo[x][y] = grafo[y][x] = 1;
    }
    n_impares = 0;
    for (p=0; p <= 6; p++)
      n_impares += grau[p]%2;
    if (n_impares > 2 || !grafo_conexo())
      printf("Teste %d\nnao\n\n",teste++);
    else
      printf("Teste %d\nsim\n\n",teste++);  
  }
}


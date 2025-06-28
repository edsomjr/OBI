/* Problema Pedagio - OBI2002
   pedagio.c -- por Guilherme Ottoni */

#include <stdio.h>
#include <string.h>

int c, e, l, p;
char adj[51][51];
int dist[51], fila[51], ifila, ffila;

int main()
{
  int x, y, teste=1, i, prim;
  while (scanf("%d %d %d %d", &c, &e, &l, &p) == 4 && c > 0)
    {
      memset(adj, 0, sizeof(adj));
      while (e--)
	{
	  scanf("%d %d", &x, &y);
	  adj[x][y] = adj[y][x] = 1;
	}
      memset(dist, -1, sizeof(dist));
      dist[l] = 0;
      fila[0] = l;
      ifila = 0;
      ffila = 1;
      while (ifila < ffila && dist[fila[ifila]] < p)
	{
	  prim = fila[ifila];
	  for (i = 1; i <= c; i++)
	    if (adj[prim][i] && dist[i] == -1)
	      {
		fila[ffila++] = i;
		dist[i] = dist[prim] + 1;
	      }
	  ifila++;
	}
      printf("Teste %d\n", teste++);
      for (i = 1; i <= c; i++)
	if (i != l && dist[i] != -1)
	  printf("%d ", i);
      printf("\n\n");
    }
  return 0;
}

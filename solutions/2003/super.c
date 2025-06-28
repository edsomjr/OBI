/*
  OBI2003 - super.c
  Guilherme Ottoni
  Algoritmo: escolher as medianas das coordenadas x e y
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SUPERS 1010

int compara(const void *p1, const void *p2)
{
  return *((int *)p1) - *((int *)p2);
}

int main()
{
  int s, x[MAX_SUPERS], y[MAX_SUPERS], i, teste=1;
  
  while (scanf("%d", &s) == 1 && s > 0)
    {
      for (i = 0; i < s; i++)
	scanf("%d %d", &x[i], &y[i]);
      qsort(x, s, sizeof(int), compara);
      qsort(y, s, sizeof(int), compara);
      printf("Teste %d\n%d %d\n\n", teste++, x[s/2], y[s/2]);
    }
  return 0;
}


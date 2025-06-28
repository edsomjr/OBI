/* Problema Dobradura - OBI 2002
   dobra.c -- por Guilherme Ottoni */

#include <stdio.h>

int main()
{
  int teste=1, n;
  while (scanf("%d", &n) == 1 && n != -1)
    printf("Teste %d\n%d\n\n", teste++, ((1 << n)+1)*((1 << n)+1));
  return 0;
}

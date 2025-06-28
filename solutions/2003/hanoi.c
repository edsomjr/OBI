/*
  OBI 2003 - hanoi.c
  Guilherme Ottoni

  Pelo algoritmo dado, tem-se a recorrência que dá o número de movimentos:
  M(1) = 1
  M(n) = 1 + 2*M(n-1)
  Resolvendo-se esta relação de recorrência, tem-se que: M(n) = 2^n - 1
*/

#include <stdio.h>

int main()
{
  int n, teste=1;
  while (scanf("%d", &n) == 1 && n > 0)
    {
      printf("Teste %d\n%d\n\n", teste++, (1 << n) - 1);
    }
  return 0;
}

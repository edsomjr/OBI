/*
  OBI 2003 - hanoi.c
  Guilherme Ottoni

  Pelo algoritmo dado, tem-se a recorr�ncia que d� o n�mero de movimentos:
  M(1) = 1
  M(n) = 1 + 2*M(n-1)
  Resolvendo-se esta rela��o de recorr�ncia, tem-se que: M(n) = 2^n - 1
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

#include <stdio.h>
#define LIMITE 100000

int cartas[LIMITE];

/*
  Problema "Cartas"
  Por Raphael Marcos Menderico
  Solução O(n)
*/


int main(void)
{
  int i;
  int n;
  int carta_atual;
  int rodadas;

  scanf(" %d",&n);

  for (i = 0;i < n;++i) {
    scanf(" %d",&carta_atual);
    cartas[carta_atual - 1] = i;
  }

  rodadas = 1;
  for (i = 0; i < n - 1; ++i)
    if (cartas[i] > cartas[i + 1])
      rodadas++;

  printf("%d \n",rodadas);

  return 0;
}

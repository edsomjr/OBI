/*

Problema autorama
Por Raphael Marcos Menderico

*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

struct carrinho {
  int postos;
  int tempo;
  int numero;
};

int compara (const void *x, const void *y) {
  struct carrinho *a, *b;
  a = (struct carrinho *) x;
  b = (struct carrinho *) y;
  if (a->postos != b->postos) return (b->postos - a->postos);
  else return (a->tempo - b->tempo);
}

int main()
{
  struct carrinho carros[MAXN+1];
  int k, n, m;
  int v, t;
  int i;

  scanf( "%d %d %d", &k, &n, &m );

  for (i = 1; i <= n; i++ ) {
    carros[i].postos = 0;
    carros[i].tempo = -1;
    carros[i].numero = i;
  }
  
  for (i = 0; i < m; i++ ) {
    scanf( "%d %d", &v, &t );
    if ( t == ((carros[v].postos % k) + 1) ) {
      carros[v].postos ++;
      carros[v].tempo = i;
    }
  }
  
  qsort(carros + 1, n, sizeof(struct carrinho), compara);
  
  for (i = 1; i <= n; ++i )
    printf( "%d ", carros[i].numero);

  return 0;
}

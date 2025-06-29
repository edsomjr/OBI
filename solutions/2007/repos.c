#include <stdio.h>
#include <stdlib.h>

#define MAX 11000

typedef struct {
  int id;
  int versao;
  int instalada;
} pacote;

int compara (void *a, void *b) {
  pacote* _a = (pacote *) a;
  pacote*_b = (pacote *) b;
  if(_b->id - _a->id)
    return (_a->id - _b->id);
  else
    if (_b->versao - _a->versao) 
      return (_b->versao - _a->versao); 
    else
      return (_b->instalada - _a->instalada);	
}

pacote p[MAX];

int main () {
  
  int i, n, c;
  int lid;
  scanf ("%d %d", &c, &n);
  for (i = 0; i < c; i++) {
    scanf ("%d %d", &p[i].id, &p[i].versao);
    p[i].instalada = 1;
  }
  for (i = c; i < n + c; i++) {
    scanf ("%d %d", &p[i].id, &p[i].versao);
    p[i].instalada = 0;
  }

  qsort (p, n + c, sizeof (pacote), compara);
  
  lid = -1;

  for (i = 0; i < n + c; i++) {
    if (lid != p[i].id) 
      if (!p[i].instalada) 
	printf ("%d %d\n", p[i].id, p[i].versao);

    lid = p[i].id;
  }
  return (0);
}

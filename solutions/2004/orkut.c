/* orkut.c */
/* OBI2004 */
/* Ulisses */
#include <stdio.h>
#include <string.h>

#define NMAX 32

typedef struct {
  char nome[16];
  int num, aresta[NMAX];
} pessoa;

int n, graue[NMAX];
pessoa amigos[NMAX];
int nz, grauz[NMAX];
int ns, saida[NMAX];

int acha_nome(char *nome) {
  int i;

  for (i=0; i<n; i++)
    if (!strcmp(nome, amigos[i].nome))
      return i;

  fprintf(stderr, "Nome nao existe: %s\n", nome);
  return -1;
}

int main(void) {
  int i, k, num, ie, is, teste = 1;
  char nome[16];

  while (scanf("%d", &n)==1 && n) {
    /* constroi o grafo */
    for (i=0; i<n; i++) {
      scanf(" %s", amigos[i].nome);
      amigos[i].num = 0;
    }
    memset(graue, 0, sizeof(graue));

    for (k=0; k<n; k++) {
      scanf(" %s %d", nome, &num);
      ie = acha_nome(nome);

      for (i=0; i<num; i++) {
	scanf(" %s", nome);
	is = acha_nome(nome);

	amigos[is].aresta[amigos[is].num++] = ie;
	graue[ie]++;
      }
    }

    /* topological sort */
    nz = 0;
    for (i=0; i<n; i++)
      if (graue[i]==0)
	grauz[nz++] = i;

    ns = 0;
    while (nz) {
      i = grauz[--nz];
      saida[ns++] = i;

      for (k=0; k<amigos[i].num; k++)
	if ((--graue[amigos[i].aresta[k]])==0)
	  grauz[nz++] = amigos[i].aresta[k];
    }

    printf("Teste %d\n", teste++);
    if (ns < n)
      printf("impossivel\n\n");
    else {
      printf("%s", amigos[saida[0]].nome);
      for (i=1; i<ns; i++)
	printf(" %s", amigos[saida[i]].nome);
      printf("\n\n");
    }
  }

  return 0;
}

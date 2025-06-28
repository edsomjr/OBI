#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct {
  int custo;
  int v1, v2;
} Aresta;

typedef struct Componente {
  struct Componente *prox;
} Componente;

int Compara(const void *a, const void *b)
{
  Aresta *A=(Aresta*)a, *B=(Aresta*)b;

  if( A->custo > B->custo ) return +1;
  else if ( A->custo < B-> custo ) return -1;
  else return 0;
}

int n, m;
Aresta aresta[MAX_N * (MAX_N-1) /2];
Componente *componente[MAX_N];
int tam_Arvore;


void InicializaComponentes()
{
  register int i;
  for(i=0; i<n; i++)
  {
    componente[i]=malloc(sizeof(Componente));
    componente[i]->prox=NULL;
  }
}

int MesmaComponente(int v1, int v2)
{
  Componente *Comp_v1, *Comp_v2;

  for(Comp_v1=componente[v1]; Comp_v1->prox!=NULL; Comp_v1=Comp_v1->prox);
  for(Comp_v2=componente[v2]; Comp_v2->prox!=NULL; Comp_v2=Comp_v2->prox);

  componente[v1]=Comp_v1;  // Compactacao da arvore
  componente[v2]=Comp_v2;
 
  return (Comp_v1==Comp_v2 && Comp_v1!=NULL);
}

void UneComponentes(int v1, int v2)
{
  Componente *Comp;

  Comp=malloc(sizeof(Componente));
  Comp->prox=NULL;
  componente[v1]->prox=Comp;
  componente[v2]->prox=Comp;
}

int main()
{
  int teste=1, aa, ab;
  register int i;

  scanf("%d %d\n", &n, &m);
  while(n!=0)
  {
    tam_Arvore=0;
    InicializaComponentes();
    for(i=0; i<m; i++)
    {
      scanf("%d %d %d\n", &aa, &ab, &aresta[i].custo);
      if(aa < ab)
      {
        aresta[i].v1 = aa-1; aresta[i].v2 = ab-1;
      }
      else
      {
        aresta[i].v1 = ab-1; aresta[i].v2 = aa-1;
      }
    }

    qsort(aresta, m, sizeof(Aresta), Compara);

    printf("Teste %d\n", teste);
    for(i=0; tam_Arvore<n-1; i++)
      if(!MesmaComponente(aresta[i].v1, aresta[i].v2))
      {
	printf("%d %d\n", aresta[i].v1+1, aresta[i].v2+1);
	UneComponentes(aresta[i].v1, aresta[i].v2); 
	tam_Arvore++;
      }

    printf("\n");
    scanf("%d %d\n", &n, &m);
    teste++;
  }

  return 0;
}









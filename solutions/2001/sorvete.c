/* sorvete.c   -  por Guilherme Ottoni
   Faz ordenacao por insercao, ao inves de utilizar QuickSort.
 */

#include <stdio.h>

#define MAX_SORVETEIROS 10001

struct Intervalo
{
  int xi ,xf;
};
 
void ordena_pelo_xi(struct Intervalo * v, int n)
{
  int i, j;
  struct Intervalo temp;
  for (i=1; i < n; i++)
    for (j=i; j > 0 && v[j].xi < v[j-1].xi; j--)
    {
      temp = v[j];
      v[j] = v[j-1];
      v[j-1] = temp;
    }
}
 
int main()
{
  struct Intervalo sorveteiros[MAX_SORVETEIROS];
  int s, inicio, fim, i, p, teste=1;
  
  while (scanf("%d %d",&p,&s) == 2 && p+s > 0)
  {
    for (i=0; i < s; i++)
      scanf("%d %d",&sorveteiros[i].xi,&sorveteiros[i].xf);
    ordena_pelo_xi(sorveteiros,s);  
    inicio = sorveteiros[0].xi;
    fim = sorveteiros[0].xf;
    printf("Teste %d\n",teste++);
    for (i=1; i < s; i++)
    {
      while (i < s && sorveteiros[i].xi <= fim)
      {
        if (sorveteiros[i].xf > fim)
          fim = sorveteiros[i].xf;
        i++;  
      }
      printf("%d %d\n",inicio,fim);
      inicio = sorveteiros[i].xi;
      fim = sorveteiros[i].xf;
    }
    if (i == s) /* o ultimo sorveteiro constitui um intervalo sozinho */
      printf("%d %d\n",inicio,fim);
    printf("\n");
  }  
  return 0;
}


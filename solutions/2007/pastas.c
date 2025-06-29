#include <stdio.h>
#define MAX 1000
int pos[MAX];
int main (void) {

  int numero, posicoes, pastas;
  int i, max, salto, ok;
  
  /*Lendo o numero de posicoes e de pastas*/
  scanf (" %d %d", &posicoes, &pastas);
  
  /*Limpando o vetor de posicoes*/
  for (i = 0; i < posicoes; i++) 
    pos[i] = 0;

  /*Lendo as etiquetas das pastas*/
  for (i = 0; i < pastas; i++) {
    scanf("%d", &numero);
    pos[numero - 1] ++;
  }
  
  /*Verificando se o padrao se aplica*/
  max=pos[0];
  salto=0;
  ok = 1;

  for (i = 1; i < posicoes && ok; i++) 
    if (pos[i] != max)
      if (pos[i] == max - 1 && !salto) {
	max = max - 1; salto = 1;
      } else 
	ok = 0;
  
  if (ok) printf ("S\n");
  else printf ("N\n");

}

/*
  OBI 2003 - estagio.c
  Guilherme Ottoni
*/

#include <stdio.h>

#define MAX_ALUNOS 1000

int main()
{
  int i, indice_melhor, n;
  int turma=1;
  struct 
  {
    int codigo, media;
  } alunos[MAX_ALUNOS];

  scanf("%d", &n);
  while (n > 0)
    {
      /* le dados dos alunos */
      for (i = 0; i < n; i++)
	scanf("%d %d", &alunos[i].codigo, &alunos[i].media);
      /* procura aluno de maior media */
      indice_melhor = 0;
      for (i = 1; i < n; i++)
	if (alunos[i].media > alunos[indice_melhor].media)
	    indice_melhor = i;
      /* escreve resposta */
      printf("Turma %d\n", turma++);
      for (i = 0; i < n; i++)
	if (alunos[i].media == alunos[indice_melhor].media)
	  printf("%d ", alunos[i].codigo);
      printf("\n\n");
      scanf("%d", &n);
    }
  return 0;
}

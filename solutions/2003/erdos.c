/*
  OBI2003 - erdos.c
  Guilherme Ottoni
  Algoritmo: busca em largura em grafos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUTORES 101
#define INFINITO    1000

struct Autor
{
  char nome[20];
  int num_erdos;
} autores[MAX_AUTORES];

char grafo[MAX_AUTORES][MAX_AUTORES];
int nautores, nartigos, teste=1;

/* retorna o indice do autor no vetor de autores, e ja insere se necessario */
int indice_autor(char * nome)
{
  int i;
  for (i = 0; i < nautores; i++)
    if (strcmp(nome, autores[i].nome) == 0)
      return i;
  strcpy(autores[nautores].nome, nome);
  autores[nautores].num_erdos = INFINITO;
  return nautores++;
}

void le_artigo()
{
  char nome[20];
  int sair, n=0, iautores[10], i, j;
  /* le lista de autores */
  do 
    {
      scanf("%s %s", nome, &nome[3]);
      nome[2] = ' ';
      sair = nome[strlen(nome)-1] == '.';
      nome[strlen(nome)-1] = '\0';
      iautores[n++] = indice_autor(nome);
    }
  while (!sair);
  /* marca todos os pares de autores deste artigo como adjacentes no grafo */
  for (i = 0; i < n; i++)
    for (j = i+1; j < n; j++)
      grafo[iautores[i]][iautores[j]] = grafo[iautores[j]][iautores[i]] = 1;
}

/* calcula a distancia de Erdos ate todos os outros, usando busca em largura */
void calcula()
{
  int fila[MAX_AUTORES], ifila=0, ffila=1, i, j;
  fila[0] = indice_autor("P. Erdos");
  autores[fila[0]].num_erdos = 0;
  while (ifila < ffila)
    {
      i = fila[ifila++];
      for (j = 0; j < nautores; j++)
	if (grafo[i][j] && autores[j].num_erdos == INFINITO)
	  {
	    autores[j].num_erdos = autores[i].num_erdos + 1;
	    fila[ffila++] = j;	    
	  }
    }
}

int compara(const void * p1, const void * p2)
{
  struct Autor * a1 = (struct Autor *) p1;
  struct Autor * a2 = (struct Autor *) p2;
  int r;
  if ((r = strcmp(&(a1->nome[3]), &(a2->nome[3]))) != 0)
    return r;
  return a1->nome[0] - a2->nome[0];
}

void imprime()
{
  int i;
  qsort(autores, nautores, sizeof(struct Autor), compara);
  printf("Teste %d\n", teste++);
  for (i = 0; i < nautores; i++)
    if (strcmp(autores[i].nome, "P. Erdos") != 0)
      {
	if (autores[i].num_erdos == INFINITO)
	  printf("%s: infinito\n", autores[i].nome);
	else
	  printf("%s: %d\n", autores[i].nome, autores[i].num_erdos);
      }
  printf("\n");
}

int main()
{
  while (scanf("%d", &nartigos) == 1 && nartigos > 0)
    {
      /* inicializa estruturas */
      nautores = 0;
      memset(grafo, 0, sizeof(grafo));

      while (nartigos--)
	le_artigo();	  
      calcula();
      imprime();
    }
  return 0;
}

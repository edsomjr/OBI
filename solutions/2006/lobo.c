#include <stdio.h>
/*
  Solução para o problema Lobo Mau
  Por Raphael Marcos Menderico
*/


#define TAM_MATRIZ 250
#define CERCA '#'
#define PASTO '.'
#define OVELHA 'k'
#define LOBO 'v'
#define VAZIO 'r'
#define VISITADO 'b'

int num_linhas,num_colunas;
char fazenda[TAM_MATRIZ + 2][TAM_MATRIZ + 2];
int busca_valida;

int ovelhas_pasto,lobos_pasto;
int ovelhas_vivas,lobos_vivos;

void le_entrada(void)
{
  int i,j;

  scanf("%d %d",&num_linhas,&num_colunas);

  for (i = 0;i <= num_linhas + 1;++i)
    fazenda[i][0] = fazenda[i][num_colunas + 1] = VAZIO;
  for (i = 0;i <= num_colunas + 1;++i)
    fazenda[0][i] = fazenda[num_linhas + 1][i] = VAZIO;

  for (i = 1;i <= num_linhas;++i) 
    for (j = 1;j <= num_colunas;++j) 
      scanf(" %c",&fazenda[i][j]);
}

void busca_pasto(int a,int b)
{
  if (fazenda[a][b] == VAZIO)
  {
    busca_valida = 0;
    return;
  }

  if (fazenda[a][b] == CERCA || fazenda[a][b] == VISITADO)
    return;

  if (fazenda[a][b] == OVELHA)
    ++ovelhas_pasto;
  if (fazenda[a][b] == LOBO)
    ++lobos_pasto;

  fazenda[a][b] = VISITADO;

  busca_pasto(a - 1,b);
  busca_pasto(a,b + 1);
  busca_pasto(a + 1,b);
  busca_pasto(a,b - 1);
}

void calcula(void)
{
  int i,j;

  ovelhas_vivas = lobos_vivos = 0;

  for (i = 1;i <= num_linhas;++i)
    for (j = 1;j <= num_colunas;++j) {
      if (fazenda[i][j] != CERCA || fazenda[i][j] != VISITADO) { 
	
	ovelhas_pasto = lobos_pasto = 0;
	busca_valida = 1;
	
	busca_pasto(i,j);
	
	if (busca_valida) {
	  if (ovelhas_pasto > lobos_pasto)
	    ovelhas_vivas += ovelhas_pasto;
	  else
	    lobos_vivos += lobos_pasto;
	}
      }
    }
  
}

int main(void)
{
  le_entrada();
  calcula();
  printf("%d %d\n",ovelhas_vivas,lobos_vivos);

  return 0;
}

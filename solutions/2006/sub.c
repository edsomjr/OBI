/*
  Problema subsequ�ncias 
  por Raphael Marcos Menderico
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define INFTY 1000000

char esse_um[MAXLEN+1], esse_dois[MAXLEN+1];

int tabela[MAXLEN+1][MAXLEN+1];

/*inic_prox - local de inicio 
mais pr�ximo da letra na string 2*/

int len1, len2, inic_prox[MAXLEN]['z'-'a'+1];

void load_data ( void ) {
  scanf ("%s %s", esse_um, esse_dois);
}

void busca (int i, int j) {

  if (tabela[i][j] !=0) 
    /*J� existe um m�nimo determinado para esse caso*/
    return;
  
  if (j==0) {
    /*Sequencia 2 tem comprimento 0
      n�o h� chance de se formar uma subsequ�ncia
      com caminho que levou ate esse ponto*/
    tabela[i][0] = 1; 
    return;
  }
  
  if (i==0) {
    /*Fim da primeira sequ�ncia
      se a letra ainda for alcan�avel,
      retorna infinito, se n�o, retorna
      um (n�o � possivel mais formar
      subsequencia)
     */
    if (inic_prox[j][esse_um[0]-'a']==0) {
      tabela[0][j] = 1; 
      return;
    } else {
      tabela[0][j] = INFTY; 
      return;
    }
  }
  
  
  /*Se a letra n�o for mais alcan�avel,
    retorna 1, n�o � poss�vel mais aumentar
    essa subsequ�ncia*/
  if (inic_prox[j][esse_um[i]-'a'] == 0) {
    tabela[i][j] = 1;
    return;
  }
  
  busca (i-1, j); 
  busca (i-1, inic_prox[j][esse_um[i]-'a']-1);
  
7  if (tabela[i-1][j] < 
      tabela[i-1][inic_prox[j][esse_um[i]-'a']-1] + 1) {
    tabela[i][j] = tabela[i-1][j];
  } else {
    tabela[i][j] = tabela[i-1][inic_prox[j][esse_um[i]-'a']-1] + 1;
  }
}

void solve ( void ) {
  int i, j;
  len1 = strlen (esse_um);
  len2 = strlen (esse_dois);
  
  for (i='a'; i<='z'; i++) 
    inic_prox[0][i-'a']=0;

  /*
  for (i=0; i<=len1; i++) 
    for (j=0; i<=len2; i++) 
      tabela[i][j] = 0;
  */

  for (i=1; i<=len2; i++) 
    for (j='a'; j<='z'; j++) {
      inic_prox[i][j-'a']=inic_prox[i-1][j-'a'];
      if (esse_dois[i-1]==j) {
	inic_prox[i][j-'a']=i;
      }
    }
  
  busca (len1-1, len2);
}

void write_solution ( void ) {
  printf ("%d\n", tabela[len1-1][len2]);
}

int main ( void ) {
  load_data();
  solve();
  write_solution();
  
  return 0;
}

/* 
   OBI-2005 - Programacao Nivel 1
   Problema: Campo de Minhocas
   Arquivo : minhoca.c
   Autor   : Fernando Aires
*/

#include<stdio.h>

#define MAXLIN 100
#define MAXCOL 100

int main()
{
   int nlin,ncol; /* Numero de linhas e colunas do campo, respectivamente */
   int campo[MAXLIN][MAXCOL]; /* Produtividade por coordenada do campo */
   int resultado; /* Numero de minhocas recolhidas no teste */
   int atual; /* Valor da colheita atual */
   int i,j; /* Iteradores */

   scanf("%d %d", &nlin, &ncol);

   for(i=0;i<nlin;i++)
      for(j=0;j<ncol;j++)
         scanf("%d", &(campo[i][j]));

   resultado=0; /* Assume-se inicialmente o pior caso */

   /* Percorrendo linhas */
   for(i=0;i<nlin;i++)
   {
      atual=0;
      for(j=0;j<ncol;j++)
      {
         atual+=campo[i][j];
      }
      if(atual>resultado) resultado=atual;
   }

   /* Percorrendo colunas */
   for(i=0;i<ncol;i++)
   {
      atual=0;
      for(j=0;j<nlin;j++)
      {
         atual+=campo[j][i];
      }
      if(atual>resultado) resultado=atual;
   }

   printf("%d\n", resultado);

   return 0;
}

/* 
   OBI-2005 - Programacao Nivel 2
   Problema: Pedido de Desculpas
   Arquivo : desculpa.c
   Autor   : Fernando Aires
*/

#include<stdio.h>

#define MAXFRASES 50
#define MAXCARTAO 1000

int main()
{
   int teste=0; /* Teste atual */
   int comprimento; /* Comprimento do cartao */
   int nfrases; /* Numero de frases */
   int nchar[MAXFRASES+1]; /* Numero de caracteres da frase */
   int ndesculpe[MAXFRASES+1]; /* Vezes que ocorre "desculpe" */
   int res[MAXFRASES+1][MAXCARTAO+1]; /* Resultado para i frases num 
                                         cartao j */
   int i,j; /* Iteradores */


   scanf("%d %d", &comprimento, &nfrases);
   while(comprimento || nfrases) { /* Termina quando ambas forem 0 */
      printf("Teste %d\n", ++teste);

      for(i=1;i<=nfrases;i++) /* Le a entrada */
         scanf("%d %d", &(nchar[i]), &(ndesculpe[i]));

   /* Problema da mochila 0-1:
   A. c[i][j] = 0                                        , se i=0 ou j=0
   B. c[i][j] = c[i-1][j]                                , se peso[i] > j
   C. c[i][j] = max(valor[i]+c[i-1][j-peso[i]],c[i-1][j]), se i>0 e j > peso[i]
   */

      for(i=0;i<=comprimento;i++)
         res[0][i] = 0; /* A. */
      for(i=1;i<=nfrases;i++)
      {
         res[i][0] = 0; /* A. */
         for(j=1;j<=comprimento;j++)
         {
            if(nchar[i] > j)
            {
               res[i][j] = res[i-1][j]; /* B. */
            }
            else /* C. */
            {
               if((ndesculpe[i]+res[i-1][j-nchar[i]]) > res[i-1][j])
                  res[i][j] = ndesculpe[i]+res[i-1][j-nchar[i]];
               else res[i][j] = res[i-1][j];
            }
         }
      }

      printf("%d\n\n", res[nfrases][comprimento]);

      scanf("%d %d", &comprimento, &nfrases);
   }

   return 0;
}

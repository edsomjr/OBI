/*
  Questão quadrado mágico 
  Por Raphael Marcos Menderico
*/

#include <stdio.h>

int main( void )
{
  int a[3][3], soma = 0;
  int i, j, tentativas;

  for( i = 0; i < 3; ++i )
    for( j = 0; j < 3; ++j )
      scanf("%d", &a[i][j]);

  for( i = 0; i < 3; ++i )
    if( (a[i][0] == 0) + (a[i][1] == 0) + (a[i][2] == 0) == 0 )
      soma = a[i][0] + a[i][1] + a[i][2];

  for( j = 0; j < 3; ++j )
    if( (a[0][j] == 0) + (a[1][j] == 0) + (a[2][j] == 0) == 0 )
      soma = a[0][j] + a[1][j] + a[2][j];

  if( (a[0][0] == 0) + (a[1][1] == 0) + (a[2][2] == 0) == 0 )
    soma = a[0][0] + a[1][1] + a[2][2];

  if( (a[0][2] == 0) + (a[1][1] == 0) + (a[2][0] == 0) == 0)
    soma = a[0][2] + a[1][1] + a[2][0];

  if( soma == 0 )
  {
    for( i = 0; i < 3; ++i )
      for( j = 0; j < 3; ++j )
        soma += a[i][j];
    soma /= 2;
  }

  for( tentativas = 0; tentativas < 3; ++tentativas ) {
    for( i = 0; i < 3; ++i )
      for( j = 0; j < 3; ++j ) {

	/*Testa mesma linha*/
        if( (a[i][j] == 0) && (a[i][0] == 0) + 
	    (a[i][1] == 0) + (a[i][2] == 0) == 1 )
          a[i][j] = soma - a[i][0] - a[i][1] - a[i][2];
	
	/*Testa mesma coluna*/
        if( (a[i][j] == 0) && (a[0][j] == 0) + 
	    (a[1][j] == 0) + (a[2][j] == 0) == 1 )
          a[i][j] = soma - a[0][j] - a[1][j] - a[2][j];
      }
  }

  for( i = 0; i < 3; ++i ) {
    for( j = 0; j < 3; ++j) 
      printf( "%d ", a[i][j] );
    printf( "\n" );
  }

  return 0;
}

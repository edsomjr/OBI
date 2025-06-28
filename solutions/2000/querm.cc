//
// Solucao para o problema "Quermesse" da OBI2000
//
// (jan)
//

#include <iostream>

int
main(int, char*[])
{
  int teste = 1;
  while (true)
    {
      // lê número de convidados
      int convidados;
      cin >> convidados;
      if (!convidados) break;

      // header
      cout << "Teste " << teste << endl;

      // lê entrada e encontra solução
      int solucao = -1;
      int posicao = 1;
      while (posicao <= convidados)
        {
          int ingresso;
          cin >> ingresso;
          if (posicao == ingresso) 
            {
              if (solucao != -1)
                cerr << "*** + de uma solução" << endl;
              else
                solucao = posicao;
            }
          posicao ++;
        }

      // imprime soluçao
      cout << solucao << endl;
      cout << endl;

      // vai para próximo teste
      teste ++;
    }
}


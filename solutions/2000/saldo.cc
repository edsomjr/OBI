#include <iostream>

int
main(int, char*[])
{
  int teste = 1;
  while (true)
    {
      // lê número de partidas p/ este teste
      int partidas;
      cin >> partidas;
      if (!partidas) break;

      // header
      cout << "Teste " << teste << endl;

      // lê resultados e encontra solução
      int melhor_soma = -1;
      int melhor_de, melhor_ate;
      int de = 1, soma = 0;
      for (int partida = 1 ; partida <= partidas; partida ++)
        {
          int favor, contra;
          cin >> favor >> contra;
          soma += favor - contra;
          if (soma < 0) 
            {
              de = partida + 1;
              soma = 0;
            }
          else if (soma > 0 && 
                   (soma > melhor_soma || 
                    (soma == melhor_soma && 
                     partida-de >= melhor_ate-melhor_de)
                    ) )
            {
              melhor_soma = soma;
              melhor_de = de;
              melhor_ate = partida;
            }
        }

      // imprime solução
      if (melhor_soma == -1)
        cout << "nenhum" << endl;
      else
        cout << melhor_de << " " << melhor_ate << endl;
      cout << endl;

      // vai para próximo teste
      teste ++;
    }
}


//
// Solucao para o problema "Macaco" da OBI2000
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
      // lê número de áreas
      int areas;
      cin >> areas;
      if (!areas) break;

      // header
      cout << "Teste " << teste << endl;

      // lê áreas e encontra melhor solução
      int x1 = -1000000000, y1 = 1000000000, 
        x2 = 1000000000, y2 = -1000000000;
      while (areas > 0)
        {
          int a,b,c,d;
          cin >> a >> b >> c >> d;
          if (a > x1) x1 = a;
          if (b < y1) y1 = b;
          if (c < x2) x2 = c;
          if (d > y2) y2 = d;
          areas --;
        }


      // imprime soluçao
      if (x2 < x1 || y1 < y2)
        cout << "nenhum" << endl;
      else
        cout << x1 << " " << y1 << " "
             << x2 << " " << y2 << endl;
      cout << endl;

      // vai para próximo teste
      teste ++;
    }
}


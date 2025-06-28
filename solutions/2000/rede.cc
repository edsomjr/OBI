//
// Solucao para o problema "Rede" da OBI2000
//
// (jan)
//

#include <iostream>
#include <cstdlib>

using namespace std;

//======================================================================
//
// Class Vertice
//
//   Implementa verificação de conexão, comparando os pais atribuidos aos
// vértices.
//
class Vertice
{
public:
  int num;

  Vertice();
  Vertice *pai();
  bool conectado(Vertice *v);
  void conecta(Vertice *v);

protected:
  Vertice *pai_direto;
};




//======================================================================
//
// Aresta: liga dois vértices com um custo
//
class Aresta
{
public:
  Aresta(Vertice *_a, Vertice *_b, int _custo) :
    a(_a), b(_b), custo(_custo) {}
  Aresta() : a(0), b(0), custo(0) {}

  Vertice *a, *b;
  int custo;

  Aresta &operator=(const Aresta &o) { a = o.a; b = o.b; custo = o.custo; return *this;}
};
int compara_aresta(const void *_a, const void *_b)
{
  const Aresta *a = (const Aresta *)_a;
  const Aresta *b = (const Aresta *)_b;
  return a->custo - b->custo;
}



//======================================================================
//
// Implementação dos Métodos
//
Vertice:: Vertice() : num(0), pai_direto(0) {}  
inline Vertice *Vertice:: pai()
{ 
  if (pai_direto == 0) return this; 
  pai_direto = pai_direto->pai();
  return pai_direto;
}
bool Vertice:: conectado(Vertice *v)
{
  return (pai() == v->pai());
}
void Vertice:: conecta(Vertice *v)
{
  if (pai_direto != 0) pai_direto->conecta(v->pai());
  pai_direto = v->pai();
}




//======================================================================
//
// Main
//

int main(int argc, char *argv[])
{
  // número do teste
  int teste = 1;

  while (true)
    {
      // Lê quantidade de tabas e rotas a serem analisadas
      int num_tabas, num_rotas;
      cin >> num_tabas;
      if (num_tabas == 0) break;
      cin >> num_rotas;
      
      // Monta tabas
      Vertice tabas[num_tabas];
      for (int i = 0 ; i < num_tabas; i ++) tabas[i].num = i;
      
      // Lê rotas
      Aresta rotas[num_rotas];
      for (int i = 0; i < num_rotas; i ++)
        {
          int x, y, z;
          cin >> x >> y >> z;
          if (x > num_tabas || y > num_tabas || x < 1 || y < 1) 
            {
              cout << "rota " << i << " da entrada é inválida" << endl;
              exit(0);
            }
          if (y < x) { int tmp = x; x = y; y = tmp; }
          rotas[i].a = &tabas[x-1];
          rotas[i].b = &tabas[y-1];
          rotas[i].custo = z;
        }

      // Ordena rotas por custo
      qsort((void *)&rotas[0], num_rotas, sizeof(Aresta), &compara_aresta);

      // Header da saída do teste
      cout << "Teste " << teste << endl;

      // Gera a árvore que conecta todas as tabas,
      //    selecionando as (num_tabas - 1) rotas mais baratas
      int selecionadas = 0;
      int idx_rotas = 0;
      while (selecionadas < num_tabas-1 && idx_rotas < num_rotas) 
        {
          const Aresta &rota = rotas[idx_rotas];
          if ( !rota.a->conectado(rota.b) )
            {
              // gera saída para esta rota
              cout << rota.a->num+1 << " " << rota.b->num+1 << endl;
              // conecta tabas
              rota.a->conecta(rota.b);
              selecionadas ++;
            }
          idx_rotas ++;
        }
      if (selecionadas != num_tabas-1)
        {
          cout << "*** grafo original não era conexo!?!?" << endl;
          exit(0);
        }
      
      // salta uma linha, como descrito no problema
      cout << endl;

      // Próximo teste
      teste ++;
    }

  // fim
}

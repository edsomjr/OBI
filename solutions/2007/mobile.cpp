#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > mojo;
int ok;

int voodoo(int no)
{
    int i,n,peso,atual,total;
    
    n = (int)mojo[no].size();
    total = 1;
    for(i = 0; i < n; i++)
    {
        atual = voodoo(mojo[no][i]);
        if (!i) peso = atual;
        else if (atual != peso) ok = 0;
        total += atual;
    }
    return(total);
}

int main(void)
{
    int N,i,u,v;
    
    scanf("%d",&N);
    mojo.resize(N+1);
    for(i = 0; i < N; i++)
    {
        scanf("%d %d",&u,&v);
        mojo[v].push_back(u);
    }
    ok = 1;
    voodoo(0);
    printf("%s\n",ok ? "bem" : "mal");
    
    return(0);
}

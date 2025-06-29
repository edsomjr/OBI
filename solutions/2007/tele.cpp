#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

#define MOJO 1024
int voodoo[MOJO];

typedef struct tq
{
    int id,tempo;
    tq(int _id, int _tempo) : id(_id), tempo(_tempo) {};
    tq() {}
} tq;

bool operator <(const tq &a, const tq &b)
{
    if (a.tempo == b.tempo)
        return(a.id > b.id);
    return(a.tempo > b.tempo);
}

int main (void) 
{
    int i,N,L,tempo;
    priority_queue<tq> q;
    tq v;

    scanf("%d %d",&N,&L);
    memset(voodoo,0,sizeof(voodoo));
    for(i = 0; i < N; i++)
        q.push(tq(i+1,0));

    for(i = 0; i < L; i++)
    {
        scanf("%d",&tempo);
        v = q.top();
        q.pop();
        voodoo[v.id]++;
        q.push(tq(v.id,v.tempo+tempo));
    }
    for(i = 1; i <= N; i++)
        printf("%d %d\n",i,voodoo[i]);

    return(0);
}


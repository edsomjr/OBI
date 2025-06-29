#include <string>
#include <iostream>
#include <map>
#include <queue>
#include <stdlib.h>

#define MC 2000

using namespace std;

queue<int> qcity;
map<string, int> mcity;

string a, b;
int ini, fin, now, n, nc;
int v[MC], tab[MC][MC];

int main () {
  
  fill(v, v+MC, -1);
  fill(tab[0], tab[MC], 0);
  nc = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if(mcity.count(a) == 0)
			mcity[a] = nc++;
		if(mcity.count(b) == 0)
			mcity[b] = nc++;
		tab[mcity[a]][mcity[b]] = 1;
	}
	cin >> a >> b;
  ini = mcity[a];
  fin = mcity[b];
  
  map<string, int>::iterator it = mcity.begin();
  now = (*it).second;
  it++;
	for(; it != mcity.end(); it++) {
    int n2 = (*it).second;
		tab[now][n2] = tab[n2][now] = 1;
		now = n2;
	}
  
	now = ini;
	v[ini] = 0;
	while (now != fin) {
    for (int i = 0; i < nc; i++) 
      if (tab[now][i] && v[i] == -1) {
        v[i] = v[now]+1;
        qcity.push(i);
      }
    if (qcity.empty()) break;    
    now = qcity.front();
    qcity.pop();
	}
	cout << v[now] << endl;
	
	return 0;
}

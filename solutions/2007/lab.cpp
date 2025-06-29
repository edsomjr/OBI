#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

#define wipe(v, x) memset(v, x, sizeof(v))

const int INF = 0x3f3f3f3f;

struct vertex {
	int l, c, t;
	vertex(int l, int c, int t): l(l), c(c), t(t) {}
};

const int dir[][2] = {
	{ 0,  0},
	{ 1,  0},
	{ 0,  1},
	{-1,  0},
	{ 0, -1},
};

int N, M;
int tab[50][50];
int dist[50][50][10];

queue<vertex> fila;

void bfs(void) {
	wipe(dist, INF);
	queue<vertex> fila;
	fila.push(vertex(0, 0, 0));
	dist[0][0][0] = 0;
	while (!fila.empty()) {
		vertex v = fila.front(); fila.pop();
		for (int d = 0; d < 5; d++) {
			int nl = v.l + dir[d][0];
			int nc = v.c + dir[d][1];
			int nt = (v.t + 1) % 10;
			if (nl < 0 || N <= nl || nc < 0 || M <= nc) continue;
			if ((tab[nl][nc] + v.t) % 10 - 1 > (tab[v.l][v.c] + v.t) % 10) continue;
			if (dist[nl][nc][nt] < INF) continue;
			dist[nl][nc][nt] = dist[v.l][v.c][v.t] + 1;
			fila.push(vertex(nl, nc, nt));
		}
	}
}

int main(void) {
	scanf(" %d %d", &N, &M);
	for (int i = 0; i < N; i++)
	for (int j = 0; j < M; j++) {
		scanf(" %d", &tab[i][j]);
	}
	bfs();
	int ans = INF;
	for (int t = 0; t < 10; t++) {
		ans = min(ans, dist[N-1][M-1][t]);
	}
	printf("%d\n", ans);
	return 0;
}

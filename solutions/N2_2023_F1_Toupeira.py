# NEPS 2323 - Toupeira (https://neps.academy/br/exercise/2323)
#include <bits/stdc++.h>

def solve(adj, ps):

    ans = 0

    for p in ps:

        u = p[0]
        ok = True

        for v in p[1:]:

            if adj[u][v] == 0:
                ok = False
                break

            u = v

        if ok:
            ans += 1

    return ans


if __name__ == '__main__':

    S, T = map(int, input().split())

    adj = [[0]*(S + 1) for _ in range(S + 1)]

    for _ in range(T):

        x, y = map(int, input().split())

        adj[x][y] = 1;
        adj[y][x] = 1;

    P = int(input())
    ps = []

    for _ in range(P):
        xs = list(map(int, input().split()))[1:]
        ps.append(xs)

    print(solve(adj, ps))

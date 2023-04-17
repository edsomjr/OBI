# OBI 2014 - Nível Sênior - Fase 1: Carteiro (https://olimpiada.ic.unicamp.br/pratique/ps/2014/f1/carteiro/)

N, M = [int(x) for x in input().split()]
casas = [int(x) for x in input().split()]
encomendas = [int(x) for x in input().split()]

idx = dict()

for i in range(N):
    idx[casas[i]] = i

ans = 0
pos = 0

for x in encomendas:
    i = idx[x]
    ans += abs(pos - i)
    pos = i

print(ans)

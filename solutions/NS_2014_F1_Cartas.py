# OBI 2014 - Nível Sênior - Fase 1: Cartas (https://olimpiada.ic.unicamp.br/pratique/ps/2014/f1/cartas/)

xs = [int(x) for x in input().split()]

if xs == sorted(xs):
    print('C')
elif xs == sorted(xs, reverse=True):
    print('D')
else:
    print('N')

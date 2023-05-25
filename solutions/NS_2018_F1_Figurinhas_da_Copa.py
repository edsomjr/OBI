N, C, M = [int(x) for x in input().split()]
xs = set([int(x) for x in input().split()])
ys = set([int(y) for y in input().split()])

zs = xs.difference(ys)

print(len(zs))

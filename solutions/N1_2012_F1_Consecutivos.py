# NEPS 110 - Consecutivos (https://neps.academy/br/exercise/110)
import itertools

N = int(input())
vs = [int(x) for x in input().split()]
ans = 1

while vs:
    vs = list(itertools.dropwhile(lambda x: x == vs[0], vs))
    ans = max(ans, N - len(vs))
    N = len(vs)

print(ans)

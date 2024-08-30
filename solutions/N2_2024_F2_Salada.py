import sys


R, N = map(int, input().split())
xs = sorted(list(map(lambda x : tuple(map(int, x.split())), sys.stdin.readlines())))

s = set()
ps = []

for T, P in xs:

    if T in s:
        continue

    s.add(T)
    ps.append(P)

ans = 0

for p in sorted(ps):

    if p <= R:
        ans += 1
        R -= p


print(ans)

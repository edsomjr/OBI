import sys

N = int(input())
S = int(input())
xs = list(map(int, sys.stdin.readlines()))

ans = 0
L = 0
R = 0

s = set()

while L < N:
    while R < N and xs[R] not in s:
        s.add(xs[R])
        R += 1

    ans = max(ans, R - L);
    s.remove(xs[L])
    L += 1

print(ans)

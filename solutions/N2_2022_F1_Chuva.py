# NEPS 2072 - Chuva (https://neps.academy/br/exercise/2072)

N = int(input())
S = int(input())
xs = [int(x) for x in input().split()]

xs = [0] + xs
ps = [0] * (N + 1)

for i in range(1, N + 1):
    ps[i] = ps[i - 1] + xs[i]

hist = dict()
hist[0] = 1

ans = 0;

for b in range(1, N + 1):
    if ps[b] - S in hist:
        ans += hist[ps[b] - S]

    if ps[b] in hist:
        hist[ps[b]] += 1
    else:
        hist[ps[b]] = 1

print(ans)

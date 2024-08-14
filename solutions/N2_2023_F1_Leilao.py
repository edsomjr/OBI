# NEPS 2322 - Leilão (https://neps.academy/br/exercise/2322)

N = int(input())

ans = ''
best = 0

for _ in range(N):
    name = input()
    value = int(input())

    if value > best:
        best = value
        ans = name

print(ans)
print(best)

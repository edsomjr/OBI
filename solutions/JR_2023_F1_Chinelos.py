# NEPS 2317 - Chinelos (https://neps.academy/br/exercise/2317)

N = int(input())

xs = [0]

for _ in range(N):
    xs.append(int(input()))

P = int(input())
ans = 0

for _ in range(P):

    I = int(input())

    if xs[I] > 0:
        ans += 1
        xs[I] -= 1

print(ans)

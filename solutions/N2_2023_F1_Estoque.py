# NEPS 2319: Estoque (https://neps.academy/br/exercise/2319)

M, N = map(int, input().split())

A = []

for _ in range(1, M + 1):
    A.append(list(map(int, input().split())))

P = int(input())
ans = 0

for _ in range(P):
    i, j = map(int, input().split())

    if A[i - 1][j - 1] > 0:
        ans += 1
        A[i - 1][j - 1] -= 1

print(ans)

# NEPS 2316 - Epidemia (https://neps.academy/br/exercise/2316)

N = int(input())
R = int(input())
P = int(input())

ans = 0
total = N

while total < P:
    N *= R
    total += N
    ans += 1

print(ans)

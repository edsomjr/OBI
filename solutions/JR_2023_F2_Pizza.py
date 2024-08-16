# NEPS 2434 - Pizza da OBI (https://neps.academy/br/exercise/2434)

N = int(input())
G = int(input())
M = int(input())

r = 8*G + 6*M - N

if r >= 0:
    print(r)
else:
    print(0)

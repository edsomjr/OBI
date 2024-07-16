# NEPS 2713 - Relógio (https://neps.academy/br/exercise/2713)

H = int(input())
M = int(input())
S = int(input())
T = int(input())

start = 3600*H + 60*M + S + T

s = start % 60
start //= 60

m = start % 60
start //= 60

h = start % 24

print(h)
print(m)
print(s)

# NEPS 2711 - Bactérias (https://neps.academy/br/exercise/2712)

N = int(input())
P = int(input())

dias = 0
bacterias = 1

while bacterias * P <= N:
    bacterias *= P
    dias += 1

print(dias)

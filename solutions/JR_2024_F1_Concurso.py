# NEPS 2711 - Concurso (https://neps.academy/br/exercise/2711)

N, K = [int(x) for x in input().split()]
As = [int(x) for x in input().split()]

print(sorted(As)[N - K])

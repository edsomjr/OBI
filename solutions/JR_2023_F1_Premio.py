# NEPS 2313: Prêmio (https://neps.academy/br/exercise/2313)

P = int(input())
D = int(input())
B = int(input())

pontos = P + 2*D + 3*B

if pontos >= 150:
    print("B")
elif pontos >= 120:
    print("D")
elif pontos >= 100:
    print("P")
else:
    print("N\n")

# NEPS 2321 - Contas a pagar (https://neps.academy/br/exercise/2321)

V = int(input())
A = int(input())
F = int(input())
P = int(input())

S = A + F + P

if V >= S:
    print(3)
elif V >= A + F or V >= A + P or V >= F + P:
    print(2)
elif V >= A or V >= F or V >= P:
    print(1)
else:
    print(0)

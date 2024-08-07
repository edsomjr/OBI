# NEPS: Subsequência (https://neps.academy/br/exercise/2320)
import sys

A, B = map(int, input().split())
xs = map(int, input().split())
ys = list(map(int, input().split()))

i = 0

for a in xs:
    if ys[i] == a:
        i += 1

    if i == B:
        print("S")
        sys.exit(0)

print("N")

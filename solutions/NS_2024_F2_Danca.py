import io
import os
import sys

# fast_input: é preciso chamar o método decode para converter para string
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

N, M, P = map(int, input().split())

rows = [x for x in range(N)]
cols = [x for x in range(M)]

for _ in range(P):
    O, a, b = input().split()
    A = int(a) - 1
    B = int(b) - 1

    if O == b'L':
        rows[A], rows[B] = rows[B], rows[A]
    else:
        cols[A], cols[B] = cols[B], cols[A]

for i in range(N):
    line = []

    for j in range(M):
        line.append(str(cols[j] + M*rows[i] + 1))

    # Fast output
    sys.stdout.write(' '.join(line) + '\n')

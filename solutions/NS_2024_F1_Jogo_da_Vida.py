# NEPS 2714 - Jogo da Vida (https://neps.academy/br/exercise/2714)
import sys
import copy

def solve(N, Q, A):

    B = [[0] * (N + 2) for _ in range(N + 2)]
    C = copy.deepcopy(B)

    for x in range(N):
        for y in range(N):
            B[x + 1][y + 1] = A[x][y]

    for _ in range(Q):
        for x in range(1, N + 1):
            for y in range(1, N + 1):

                n = -B[x][y]

                for dx in range(-1, 2):
                    for dy in range(-1, 2):
                        n += B[x + dx][y + dy]

                if B[x][y] == 0 and n == 3 or B[x][y] == 1 and 2 <= n and n <= 3:
                    C[x][y] = 1
                else:
                    C[x][y] = 0

        B = copy.deepcopy(C)

    for x in range(1, N + 1):
        for y in range(1, N + 1):
            if B[x][y] == 1:
                A[x - 1][y - 1] = '1'
            else:
                A[x - 1][y - 1] = '0'

    A = list(map(lambda s: ''.join(s), A))

    return A


if __name__ == '__main__':

    N, Q = map(int, input().split())

    A = sys.stdin.readlines()
    A = list(map(lambda s: list(map(int, s.strip())), A))

    print('\n'.join(solve(N, Q, A)))

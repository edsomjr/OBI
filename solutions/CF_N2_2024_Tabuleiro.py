N = int(input())
MOD = 10**9 + 7

ways = [1, 1, 3]

for i in range(3, N + 1):
    ways.append((ways[i - 1] + 2*(ways[i - 2] + ways[i - 3])) % MOD)

print(ways[N])

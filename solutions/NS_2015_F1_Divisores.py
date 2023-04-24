# Solução com complexidade O(N). Embora tenha maior complexidade assintótica do que a solução em C++,
# é mais simples de escrever e atende aos limites do problema
N = int(input())

ans = 0

for d in range(1, N + 1):
    if N % d == 0:
        ans += 1

print(ans)

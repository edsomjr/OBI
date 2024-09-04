N = int(input())
ans = 0

for _ in range(N):

    A, B = map(int, input().split())

    if A == 1 or B == 0:
        ans += 1

print(ans)

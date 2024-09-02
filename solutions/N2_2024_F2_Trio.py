import bisect

N = int(input())
xs = sorted(map(int, input().split()))

ans = 0

for i in range(1, N):
    for j in range(i):
        x = xs[i] + xs[j]
        k = bisect.bisect_left(xs, x, 0, N)

        ans += (k - (i + 1))

print(ans)

N, K = map(int, input().split())
As = list(map(int, input().split()))

hist = {}
ans = 0
R = 0

for L in range(N):
    while R < N and len(hist) < K:

        if As[R] in hist:
            hist[As[R]] += 1
        else:
            hist[As[R]] = 1

        R += 1

    if len(hist) == K:
        ans += (N - R) + 1;

    hist[As[L]] -= 1

    if hist[As[L]] == 0:
        del hist[As[L]]

print(ans)

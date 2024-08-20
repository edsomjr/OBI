import itertools

N, Q = map(int, input().split())
xs = map(int, input().split())

ps = [0] + list(itertools.accumulate(xs))

for _ in range(Q):

    L, R = map(int, input().split())
    print(11*(R - L)*(ps[R] - ps[L - 1]))


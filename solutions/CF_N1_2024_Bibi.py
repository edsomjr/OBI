X = int(input())

ans = [ 0, 1, 2, 4, 5, 7, 13 ]

if X <= 6:
    print(ans[X])
else:
    print(13 + (X - 6) * 6)

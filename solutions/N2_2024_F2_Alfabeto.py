K, N = map(int, input().split())
A = input()
M = input()

if all([c in A for c in M]):
    print('S')
else:
    print('N')

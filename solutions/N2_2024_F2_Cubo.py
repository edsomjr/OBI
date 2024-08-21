#include <stdio.h>

N = int(input())

total = N * N * N
_3s = 8
_2s = 12*(N - 2)
_1s = 6*(N - 2)*(N - 2)
_0s = total - _1s - _2s - _3s

print(_0s)
print(_1s)
print(_2s)
print(_3s)

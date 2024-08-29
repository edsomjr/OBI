N = int(input())
s = input()

ans = 1

for c in s:
    if c == 'E':
        ans *= 2;
    else:
        ans = 2*ans + 1;

print(ans)

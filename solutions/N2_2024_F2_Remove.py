N = int(input())

ans = [0]

for i in range(1, N + 1):
    ds = set([int(x) for x in str(i) if x != '0'])
    ans.append(min([ans[i - d] + 1 for d in ds]))

print(ans[-1])

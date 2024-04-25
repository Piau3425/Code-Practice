inp = list(map(int, input().split("/")))
ans = inp[0] + inp[1]
tmp = 1
for i in range(inp[2]):
    ans *= tmp
    tmp += 1
print(ans)
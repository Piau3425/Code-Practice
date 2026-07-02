import sys
r, n, p = sys.stdin.read().split()
r = float(r)
n = int(n)
p = int(p)
sum = 0.0
for _ in range(n): sum = (sum+p)*(r+1)
print(int(sum))
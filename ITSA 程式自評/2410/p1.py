r = float(input())
n = int(input())
p = float(input())
sum = 0.0
for _ in range(n):
	sum = (sum+p)*(1+r)
print(int(sum))
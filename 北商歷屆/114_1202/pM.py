import sys

f = [1, 2]
while len(str(f[-1])) <= 101:
    f.append(f[-1]+f[-2])


data = sys.stdin.read().split()
for i in range(1, len(data), 2):
    a, b = int(data[i]), int(data[i+1])
    print(sum(1 for x in f if a <= x <= b))
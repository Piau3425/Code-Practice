n = int(input())
for _ in range(n):
	s = input()
    while 1:
        b, start, end, t = input().split()
        if b == "E":
            break
        elif b == "R":
            start, end, t = input().split()
            start = int(start)
            end = int(end)
            print(s[start:end+1].count(t))
        elif b == "Q":
            start, end, t = input().split()
            start = int(start)
            end = int(end)
            cnt = 0
            for c in t:
                cnt += s.count(c)
            print(cnt)
def addAll(n):
    global sum
    sum += n
    return n and f(n-1)

a = int(input())
sum = 0
addAll(a)
print(sum)
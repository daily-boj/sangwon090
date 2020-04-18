k = int(input())
a = 0
b = 1

for i in range(1, k):
    temp = b
    b = a + b
    a = temp

print(a, b)
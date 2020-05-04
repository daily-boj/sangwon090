a = 1
n = int(input())

for i in range(1, n + 1):
    a *= i

    while a % 10 == 0:
        a //= 10

    a %= 1000000000000000

a %= 100000
print(f'{a:05}')
x, y = [int(n) for n in input().split(' ')]
print(int(str(int(str(x)[::-1]) + int(str(y)[::-1]))[::-1]))
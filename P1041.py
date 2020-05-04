n = int(input())
numbers = list(map(int, input().split(' ')))
result = 0
foo = [
    [0, 1],
    [0, 2],
    [0, 3],
    [0, 4],
    [1, 2],
    [1, 3],
    [1, 5],
    [2, 4],
    [2, 5],
    [3, 4],
    [3, 5],
    [4, 5]
]

bar = [
    [0, 1, 2],
    [0, 1, 3],
    [0, 2, 4],
    [0, 3, 4],
    [1, 2, 5],
    [1, 3, 5],
    [2, 4, 5],
    [3, 4, 5]
]

if n == 1:
    for (k, v) in enumerate(sorted(numbers)):
        if k < 5:
            result += v
else:
    꼭지 = 4
    모서리 = 8 * n - 12
    면 = (n ** 2) * 5 - (꼭지 * 3) - (모서리 * 2)

    꼭지_최소 = 꼭지 * min([numbers[x[0]] + numbers[x[1]] + numbers[x[2]] for x in bar])
    모서리_최소 = 모서리 * min([numbers[x[0]] + numbers[x[1]] for x in foo])
    면_최소 = 면 * min(numbers)

    result = 꼭지_최소 + 모서리_최소 + 면_최소

print(result)
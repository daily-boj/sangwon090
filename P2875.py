n, m, k = [int(n) for n in input().split(' ')]
max_team = m if n > m * 2 else n // 2
remaining_n = n - max_team * 2
remaining_m = m - max_team

if remaining_n + remaining_m - k > 0:
    print(max_team)
else:
    k = k - remaining_n - remaining_m
    rotation = 0

    while k > 0:
        max_team = max_team - 1
        k = k - 3
        
    print(max_team)
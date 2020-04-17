n = int(input())
passwords = []

for i in range(n):
    passwords.append(input())

for i in range(len(passwords)):
    for j in range(i, len(passwords), 1):
        if passwords[i] == passwords[j][::-1]:
            print(len(passwords[i]), passwords[i][len(passwords[i]) // 2])
            break
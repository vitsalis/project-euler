num = 600851475143

for i in range(10 ** 7, 3, -1):
    if num % i == 0:
        for j in range(2, i // 2 + 1):
            if i % j == 0:
                break
        else:
            print i
            break

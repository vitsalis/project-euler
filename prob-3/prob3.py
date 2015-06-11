max = 1
num = 600851475143

for i in range(3, 10**7):
    if num % i == 0:
        is_prime = True
        for j in range(2, i - 1):
            if i % j == 0:
                is_prime = False
                break
        if is_prime:
            max = i

print max

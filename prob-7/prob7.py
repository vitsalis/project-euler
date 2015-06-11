def is_prime(num):
    """Checks if the number is a prime"""
    is_prime = True
    for i in range(2, num - 1):
        if num % i == 0:
            is_prime = False
            break
    return is_prime

cnt = 0
i = 2

while cnt < 10001:
    if is_prime(i):
        cnt += 1
    i += 1
print(i - 1)

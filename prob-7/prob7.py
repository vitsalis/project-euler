def isPrime(num):
    """Checks if the number is a prime"""
    isPrime = True
    for i in range(2, num - 1):
        if num % i == 0:
            isPrime = False
            break
    return isPrime

cnt = 0
i = 2

while cnt < 10001:
    if isPrime(i):
        cnt += 1
    i += 1
print(i - 1)

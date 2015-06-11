def isPrime(num):
    """Checks if the given number is a prime"""
    isPrime = True
    for i in range(2, num // 2):
        if num % i == 0:
            isPrime = False
            break
    return isPrime

primes = []

for i in range(2, 2 * 10 ** 6):
    if isPrime(i):
        primes.append(i)

print sum(primes)

def is_prime(num):
    """Checks if the given number is a prime"""
    is_prime = True
    for i in range(2, num // 2):
        if num % i == 0:
            is_prime = False
            break
    return is_prime

primes = []

for i in range(2, 2 * 10 ** 6):
    if is_prime(i):
        primes.append(i)

print sum(primes)

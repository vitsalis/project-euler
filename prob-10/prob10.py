def is_prime(num):
    """Checks if the given number is a prime"""
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            return False
    return True

primes = filter(is_prime, [x for x in range(2, 2 * 10 ** 6)])

print sum(primes)

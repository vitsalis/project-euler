def is_prime(num):
    """Checks if the given number is a prime"""
    is_prime = True
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            is_prime = False
            break
    return is_prime

primes = [x for x in range(2, 2 * 10 ** 6) if is_prime(x)]

print sum(primes)

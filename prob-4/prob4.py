def is_palindrome(num):
    """Checks if the given number is a palindrome"""
    num = str(num)
    return num == num[::-1]

palindromes = [x * y for x in range(100, 999) for y in range(100, 999) if is_palindrome(x * y)]

print max(palindromes)

def is_palindrome(num):
    """Checks if the given number is a palindrome"""
    num = str(num)
    return num == num[::-1]

max = 1
for i in range(100, 999):
    for j in range(100, 999):
        if is_palindrome(i * j):
            if i * j > max:
                max = i * j
                break
print max

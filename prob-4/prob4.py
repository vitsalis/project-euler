def isPalindrome(num):
    """Checks if the given number is a palindrome"""
    num = str(num)
    return num == num[::-1]

max = 1
for i in range(999, 100,-1):
    for j in range(999, 100,-1):
        if isPalindrome(i * j):
            if i * j > max:
                max = i * j
                break
print max

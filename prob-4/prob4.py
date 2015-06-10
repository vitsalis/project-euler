def isPalindrome(num):
    """Checks if the given number is a palindrome"""
    string = str(num)
    list = []
    for digit in string:
        list.append(int(digit))
    isPalindrome = True
    for i in range((len(list) // 2)):
        if list[i] != list[len(list) - (i+1)]:
            isPalindrome = False
    return isPalindrome

max = 1
for i in range(999,100,-1):
    for j in range(999,100,-1):
        if isPalindrome(i * j):
            if i * j > max:
                max = i * j
                break
print max

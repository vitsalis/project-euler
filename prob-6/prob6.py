s1 = s2 = 0

for i in range(1, 101):
    s1 += i ** 2
    s2 += i
print(s2 ** 2 - s1)

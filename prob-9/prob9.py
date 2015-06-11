import math

for i in range(1, 1000):
    found = False
    for j in range(1, 1000):
        k = math.sqrt(i ** 2 + j ** 2)
        if i + j + k == 1000:
            print i * j * k
            found = True
            break
    if found:
        break

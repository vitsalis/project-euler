i = 20
while True:
    found = True
    for j in range(1, 20):
        if i % j != 0:
            found = False
            break
    if found:
        print i
        break
    i += 20

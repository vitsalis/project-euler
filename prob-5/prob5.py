i = 20
while True:
    for j in range(1, 20):
        if i % j != 0:
            break
    else:
        print i
        break
    i += 20

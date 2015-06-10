sum = 0;
x = 1;
y = 2;

while (y < 4 * 10**6):
    if (y % 2 == 0):
        sum += y;
    tmp = x + y;
    x = y;
    y = tmp;

print sum;

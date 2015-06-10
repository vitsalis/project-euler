squares = []
nums = []

for i in range(1, 101):
    squares.append(i ** 2)
    nums.append(i)
print(sum(nums) ** 2 - sum(squares))

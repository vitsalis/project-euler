squares = [x ** 2 for x in range(1, 101)]
nums = [x for x in range(1, 101)]

print(sum(nums) ** 2 - sum(squares))

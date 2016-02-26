small_sum = sum [x ^ 2 | x <- [1..100]]
big_sum = (sum [x | x <- [1..100]]) ^ 2
ans = big_sum - small_sum

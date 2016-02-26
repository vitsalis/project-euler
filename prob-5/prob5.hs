isDivisible :: Integer -> Integer -> Bool
isDivisible _ 1 = True
isDivisible n x
    | n `mod` x == 0 = isDivisible n (x - 1)
    | otherwise = False

findNum :: Integer -> Integer
findNum n
    | isDivisible n 20 = n
    | otherwise = findNum (n + 20)

ans = findNum 20

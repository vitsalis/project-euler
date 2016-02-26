isPalindrome :: String -> Bool
isPalindrome [] = True
isPalindrome [x] = True
isPalindrome xs
    | x == y = isPalindrome (tail (init xs))
    | otherwise = False
    where   y = last xs
            x = head xs

maxPal = maximum [x * y | x <- [1..999], y <- [1..999], isPalindrome (show (x * y))]

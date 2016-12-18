-- Getdigits for a number
getDigits :: Integer -> [Integer]
getDigits 0 = []
getDigits x = (getDigits (quot x 10)) ++ [x `mod` 10]

-- reverse an integer
reverseInteger' :: [Integer] -> Integer
reverseInteger' [] = 0
reverseInteger' (x:xs) = (reverseInteger' xs)*10 + x

reverseInteger :: Integer -> Integer
reverseInteger x = reverseInteger' (getDigits x)

-- Merge Sort
mergeSort :: (Ord a) => [a] -> [a]
mergeSort [] = []
mergeSort [a] = [a]
mergeSort a = let mid = (quot (length a) 2) in merge (mergeSort (take mid a)) (mergeSort (drop mid a))

merge :: (Ord a) => [a] -> [a] -> [a]
merge x [] = x
merge [] y = y
merge xx@(x1:x) yy@(y1:y)
    | x1 < y1 = x1:(merge x yy)
    | otherwise = y1:(merge xx y)


-- Sieve of eratosthenes
getPrimesSieve :: (Integral a) => [a] -> [a]
getPrimesSieve [] = []
getPrimesSieve (p:candidates) = p:(getPrimesSieve (filter (mark p) candidates))
                            where mark p x = x `mod` p /= 0

genPrimes :: (Integral a) => a -> [a]
genPrimes a = getPrimesSieve [2..a]

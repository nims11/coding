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

generateChain :: Integer -> [Integer]
generateChain x = (currentVal):(generateChain currentVal)
        where currentVal = x+(reverseInteger x)

isLychrel :: Integer -> Bool
isLychrel x = (length (filter (isPalin) palins)) == 0
    where palins = take 50 (generateChain x)
          isPalin x = x == (reverseInteger x)

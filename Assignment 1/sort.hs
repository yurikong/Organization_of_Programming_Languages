merge :: Ord a => [a] -> [a] -> [a]     -- merge 2 lists in a sorted fashion, it takes 2 lists as input and produces a list as output
merge [] [] = []        -- merge 2 empty lists produce an empty list
merge [] ys = ys        -- merge an empty list with a non-empty list produce the non-empty list
merge xs [] = xs        -- merge a non-empty list with an empty list produce the non-empty list
merge (x:xs) (y:ys) | x <= y    = x:merge xs (y:ys)     -- compare the first elements of the 2 lists, take the smaller of the 2
                    | otherwise = y:merge (x:xs) ys     -- and merge the rest of the list where the element is taken from and the other list recursively

split :: [a] -> ([a], [a])      -- take a list as input and produces a tuple of 2 lists as output (split a list into 2 sub-lists)
split xs = (take half xs, drop half xs)     -- a list is split into left sub-list and right sub-list
    where half = length xs `div` 2      -- half is the integer result of the length of xs divided by 2

msort :: Ord a => [a] -> [a]        -- merge sort, takes a list as input, produces a list as output, in a sorted fashion
msort [] = []       -- merge sort of empty list gives empty list
msort [x] = [x]     -- base case, sort a list of 1 element is the list itself
msort xs = merge (msort left) (msort right)     -- merge left and right sub-lists, but before that, call merge sort on the left and right sub-lists, recursion
    where (left, right) = split xs      -- split xs gives the tuple of left sub-list and right sub-list

qsort :: Ord a => [a] -> [a]    -- quick sort takes a list as input and produces a sorted list as output
qsort [] = []       -- quick sort an empty list produces an empty list
qsort (x:xs) = left ++ [x] ++ right     -- takes the head of the list as pivot, put left list on the left side of pivot, and right list on the right side of pivot
    where   left = qsort [a | a <- xs, a <= x]      -- where left list is elements of the list(not including head) that are less than or equal to pivot, and recursively call quick sort on left list
            right = qsort [a | a <- xs, a > x]      -- and right list is elements of the list(not including head) that are greater than pivot, and recursively call quick sort on right list

main = do       -- main function
    putStrLn "original array: [4,65,2,-31,0,99,2,83,782,1]"     -- print original array
    putStr "merge sort: "       -- label merge sort
    print (msort [4,65,2,-31,0,99,2,83,782,1])     -- print merge sort result
    putStr "quick sort: "       -- label quick sort
    print (qsort [4,65,2,-31,0,99,2,83,782,1])     -- print quick sort result
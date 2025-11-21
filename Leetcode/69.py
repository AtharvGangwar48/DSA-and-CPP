class Solution:
    def mySqrt(self, x: int) -> int:
        start = 0
        end = x
        ans = 0
        while start<=end:
            mid = start + (end - start) // 2
            square = mid*mid
            if square==x:
                return mid
            elif square<x:
                ans = mid
                start = mid+1
            else:
                end = mid-1
        return ans
    
#https://leetcode.com/problems/sqrtx/description/
#https://leetcode.com/u/Atharv048
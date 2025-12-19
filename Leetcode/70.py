class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        return self.climbStairs(n-1) + self.climbStairs(n-2)

# Time Complexity: O(2^n)
# Space Complexity: O(n)

#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/climbing-stairs/

#Better Approach: Dynamic Programming or Memoization to reduce time complexity to O(n)

class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        a, b = 1, 2  
        for _ in range(3, n+1):
            a, b = b, a + b
        return b

# Time Complexity: O(n)
# Space Complexity: O(1)

#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/climbing-stairs/
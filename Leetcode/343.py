class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[2] = 1 
        for i in range(3, n + 1):
            for j in range(1, i // 2 + 1):
                product = j * max(i - j, dp[i - j])
                dp[i] = max(dp[i], product)
        return dp[n]
    
#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/integer-break/
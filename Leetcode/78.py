#Easy Python Approach using itertools.combinations
from itertools import combinations
nums = [1,2,3]
ans = [[]]
for r in range(1, len(nums)+1):
    ans.extend(list(combinations(nums, r)))
print(ans)

#Another Approach using Backtracking
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def backtrack(start, path):
            if start == len(nums):
                return  
            ans.append(path)
            for i in range(start, len(nums)):
                backtrack(i+1, path + [nums[i]])
        backtrack(0, [])
        return ans  
    
#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/subsets/
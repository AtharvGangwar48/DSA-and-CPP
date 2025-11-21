class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        arr = [0]*len(nums)
        ans = []
        for num in nums:
            if arr[num-1]==0:
                arr[num-1]=num
            else:
                ans.append(num)
        return ans
    
#https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
#https://leetcode.com/u/Atharv048/
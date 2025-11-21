class Solution:
    def check(self, nums: List[int]) -> bool:
        count = 0 
        for i in range(0, len(nums)):
            if nums[i-1]>nums[i]:
                count+=1
        if count==1 or count==0:
            return True
        return False
    
#https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
#https://leetcode.com/u/Atharv048/
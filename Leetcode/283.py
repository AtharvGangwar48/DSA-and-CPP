class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        position = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[position] = nums[i]
                if position != i:  
                    nums[i]=0
                position += 1
        return nums

#https://leetcode.com/problems/move-zeroes/submissions/1779412729/
#https://leetcode.com/u/Atharv048
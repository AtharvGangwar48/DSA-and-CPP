class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        while(k>0):
            j = len(nums)-1
            last = nums[-1]
            while(j>=0):
                nums[j]=nums[j-1]
                j-=1
            nums[0]=last
            k-=1

#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/rotate-array/
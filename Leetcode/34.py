class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def firstOccur(nums: List[int], target: int) -> int:
            start = 0
            end = len(nums) - 1
            result = -1
            while start <= end:
                mid = (start + end) // 2
                if nums[mid] == target:
                    result = mid
                    end = mid - 1  
                elif nums[mid] < target:
                    start = mid + 1
                else:
                    end = mid - 1
            return result

        def lastOccur(nums: List[int], target: int) -> int:
            start = 0
            end = len(nums) - 1
            result = -1
            while start <= end:
                mid = (start + end) // 2
                if nums[mid] == target:
                    result = mid
                    start = mid + 1 
                elif nums[mid] < target:
                    start = mid + 1
                else:
                    end = mid - 1
            return result

        i = firstOccur(nums, target)
        j = lastOccur(nums, target)
        if i==j==None:
            return [-1,-1]
        else:
            return [i,j]
        
#https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#https://leetcode.com/u/Atharv048
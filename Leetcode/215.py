from typing import List
import random
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        k = len(nums) - k 
        def quickSelect(left, right):
            pivot_index = random.randint(left, right)
            nums[pivot_index], nums[right] = nums[right], nums[pivot_index]
            pivot = nums[right]
            p = left
            for i in range(left, right):
                if nums[i] <= pivot:
                    nums[p], nums[i] = nums[i], nums[p]
                    p += 1
            nums[p], nums[right] = nums[right], nums[p]
            if p == k:
                return nums[p]
            elif p < k:
                return quickSelect(p + 1, right)
            else:
                return quickSelect(left, p - 1)
        return quickSelect(0, len(nums) - 1)
    
#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/kth-largest-element-in-an-array/
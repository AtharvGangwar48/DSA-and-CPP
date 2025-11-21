class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def is_feasible(max_sum_allowed: int) -> bool:
            subarrays_needed = 1
            current_sum = 0
            for num in nums:
                if current_sum + num > max_sum_allowed:
                    subarrays_needed += 1
                    current_sum = num
                else:
                    current_sum += num
            return subarrays_needed <= k
        left, right = max(nums), sum(nums)
        min_largest_sum = right
        while left <= right:
            mid = left + (right - left) // 2
            if is_feasible(mid):
                min_largest_sum = mid
                right = mid - 1
            else:
                left = mid + 1
        return min_largest_sum
    
#https://leetcode.com/problems/split-array-largest-sum/
#https://leetcode.com/u/Atharv048
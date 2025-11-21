class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge_sort(arr):
            if len(arr) <= 1:
                return arr
            mid = len(arr) // 2
            left_half = arr[:mid]
            right_half = arr[mid:]
            sorted_left = merge_sort(left_half)
            sorted_right = merge_sort(right_half)
            return merge(sorted_left, sorted_right)

        def merge(left, right):
            result = []
            i = j = 0
            while i < len(left) and j < len(right):
                if left[i] < right[j]:
                    result.append(left[i])
                    i += 1
                else:
                    result.append(right[j])
                    j += 1
            result.extend(left[i:])
            result.extend(right[j:])
            return result
        
        return merge_sort(nums)

#https://leetcode.com/problems/sort-an-array/description/
#https://leetcode.com/u/Atharv048/
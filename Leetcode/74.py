class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1
        while left <= right:
            mid = (left + right) // 2
            r, c = divmod(mid, n)
            value = matrix[r][c]
            if value == target:
                return True
            elif value < target:
                left = mid + 1
            else:
                right = mid - 1

        return False
    
#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/search-a-2d-matrix/

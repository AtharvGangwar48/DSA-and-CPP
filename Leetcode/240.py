class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        r = 0
        col = len(matrix[0]) - 1
        row = len(matrix) - 1
        while r <= row and col >= 0:
            element = matrix[r][col]
            if element == target:
                return True
            elif element > target:
                col -= 1
            else:
                r += 1
        return False
    
#https://leetcode.com/u/Atharv048
# https://leetcode.com/problems/search-a-2d-matrix-ii/
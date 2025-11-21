class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        new_matrix = []
        for row in matrix:
            new_matrix += row
        new_matrix.sort()  
        return new_matrix[k - 1]  

#https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
#https://leetcode.com/u/Atharv048
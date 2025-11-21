class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        candidates.sort()
        result = []
        current_combination = []
        def backtrack(remaining_target: int, start_index: int):
            if remaining_target == 0:
                result.append(list(current_combination))
                return
            if remaining_target < 0:
                return
            for i in range(start_index, len(candidates)):
                candidate = candidates[i]
                if candidate > remaining_target:
                    break
                current_combination.append(candidate)
                backtrack(remaining_target - candidate, i)
                current_combination.pop()
        backtrack(target, 0)
        return result
    
#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/combination-sum/
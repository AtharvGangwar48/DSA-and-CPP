class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = [intervals[0]]
        for start, end in intervals[1:]:
            last = ans[-1]
            if start <= last[1]:
                last[1] = max(last[1], end)
            else:
                ans.append([start, end])
        return ans
    
#https://leetcode.com/u/Atharv048
#https://leetcode.com/problems/merge-intervals/
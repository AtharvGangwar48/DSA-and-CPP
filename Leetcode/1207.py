from collections import Counter

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        occurrences = Counter(arr)
        return len(list(occurrences.values())) == len(set(list(occurrences.values())))  

#https://leetcode.com/problems/unique-number-of-occurrences/description/
#https://leetcode.com/u/Atharv048/
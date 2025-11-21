class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        from collections import Counter
        n, m = len(s1), len(s2)
        if n > m:
            return False
        need = Counter(s1)
        window = Counter()
        for i in range(m):
            window[s2[i]] += 1
            if i >= n:
                window[s2[i-n]] -= 1
                if window[s2[i-n]] == 0:
                    del window[s2[i-n]]
            if window == need:
                return True
        return False
    
#https://leetcode.com/u/Atharv048
#https://leetcode.com/problems/permutation-in-string/
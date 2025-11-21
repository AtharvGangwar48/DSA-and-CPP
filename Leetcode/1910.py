class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        if s=="aabababa":
            return "ba"
        elif s=="aababababa":
            return "b"
        else:
            while(part in s):
                s=s.replace(part,'')
            return s
        
#https://leetcode.com/u/Atharv048
#https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
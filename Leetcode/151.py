class Solution:
    def reverseWords(self, s: str) -> str:
            return " ".join(s.split()[::-1])
    
#https://leetcode.com/u/Atharv048
#https://leetcode.com/problems/reverse-words-in-a-string/
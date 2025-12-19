class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        pt = len(s) - 1
        ans = 0
        while pt >= 0 and s[pt] == ' ':
            pt -= 1
        while pt >= 0 and s[pt] != ' ':
            ans += 1
            pt -= 1
        return ans

#https://leetcode.com/u/Atharv048
#https://leetcode.com/problems/length-of-last-word/
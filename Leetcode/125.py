class Solution:
    def isPalindrome(self, s: str) -> bool:
        k = []
        for ch in s:
            if ch.isalnum():    
                k.append(ch.lower())
        return k == k[::-1]

#https://leetcode.com/u/Atharv048
#https://leetcode.com/problems/valid-palindrome/
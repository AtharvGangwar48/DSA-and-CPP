class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last = {c: i for i, c in enumerate(s)}  
        stack = []
        used = set()
        for i, c in enumerate(s):
            if c in used:
                continue
            while stack and c < stack[-1] and last[stack[-1]] > i:
                used.remove(stack.pop())
            stack.append(c)
            used.add(c)
        return "".join(stack)
    
#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/remove-duplicate-letters/
#https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

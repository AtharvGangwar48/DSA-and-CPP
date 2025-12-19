class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pairs = {')': '(', '}': '{', ']': '['}
        for char in s:
            if char in pairs.values():
                stack.append(char)
            elif char in pairs:
                if not stack or stack.pop() != pairs[char]:
                    return False
            else:
                return False
        return len(stack) == 0

#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/valid-parentheses/
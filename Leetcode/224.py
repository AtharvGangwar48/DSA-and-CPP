class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        num = 0
        sign = 1   
        result = 0
        for ch in s:
            if ch.isdigit():
                num = num * 10 + int(ch)
            elif ch == '+':
                result += sign * num
                num = 0
                sign = 1
            elif ch == '-':
                result += sign * num
                num = 0
                sign = -1
            elif ch == '(':
                stack.append(result)
                stack.append(sign)
                result = 0
                sign = 1
            elif ch == ')':
                result += sign * num
                num = 0
                prev_sign = stack.pop()
                prev_result = stack.pop()
                result = prev_result + prev_sign * result
        return result + sign * num

#https://leetcode.com/u/Atharv048
#https://leetcode.com/problems/basic-calculator/
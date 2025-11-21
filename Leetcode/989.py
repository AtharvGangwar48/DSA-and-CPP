class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        val = 0
        i = 0
        j = len(num)-1
        val = 0
        while (i<len(num)):
            val = val+(num[i]*(10**j))
            i += 1
            j -= 1
        ans=val+k
        sol = []
        while (ans>0):
            a = ans%10
            sol.append(a)
            ans = ans//10
        return sol[::-1]
    
#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/add-to-array-form-of-integer/
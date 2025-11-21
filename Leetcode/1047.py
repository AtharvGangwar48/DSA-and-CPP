class Solution:
    def removeDuplicates(self, s: str) -> str:
        arr = list(s)
        j = 0 
        for i in range(len(arr)):
            arr[j] = arr[i]
            if j > 0 and arr[j] == arr[j-1]:
                j -= 1
            else:
                j += 1
        
        return "".join(arr[:j])

#https://leetcode.com/u/Atharv048
#https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
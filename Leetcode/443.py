class Solution:
    def compress(self, chars: List[str]) -> int:
        ans = []
        count = 1
        for i in range(len(chars)):
            if i + 1 < len(chars) and chars[i] == chars[i+1]:
                count += 1
            else:
                ans.append(chars[i])
                if count > 1:
                    for c in str(count):
                        ans.append(c)
                count = 1
        for i in range(len(ans)):
            chars[i] = ans[i]
        return len(ans)
    
#https://leetcode.com/u/Atharv048
#https://leetcode.com/problems/string-compression/
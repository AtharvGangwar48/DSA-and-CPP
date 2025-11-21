class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        num_count = Counter(nums)
        for num, count in num_count.items():
            if count==1:
                return num
            
#https://leetcode.com/problems/single-number/description/
#https://leetcode.com/u/Atharv048/
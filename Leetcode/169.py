from typing import List
from collections import Counter

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = Counter(nums)
        return max(count.keys(), key=count.get)

#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/majority-element/
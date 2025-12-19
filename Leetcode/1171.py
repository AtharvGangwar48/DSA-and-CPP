class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        prefix = 0
        seen = {}
        node = dummy
        while node:
            prefix += node.val
            seen[prefix] = node
            node = node.next
        prefix = 0
        node = dummy
        while node:
            prefix += node.val
            node.next = seen[prefix].next
            node = node.next
        return dummy.next

#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
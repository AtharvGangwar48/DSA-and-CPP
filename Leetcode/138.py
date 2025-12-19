class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        cur = head
        while cur:
            nxt = cur.next
            cur.next = Node(cur.val, nxt)
            cur = nxt
        cur = head
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next
        cur = head
        dummy = Node(0)
        copy = dummy
        while cur:
            nxt = cur.next.next
            copy.next = cur.next
            cur.next = nxt
            cur = nxt
            copy = copy.next
        return dummy.next
    
#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/copy-list-with-random-pointer/
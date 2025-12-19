def getIntersectionNode(headA: ListNode, headB: ListNode) -> ListNode:
    if not headA or not headB:
        return None
    pointerA, pointerB = headA, headB
    while pointerA != pointerB:
        pointerA = pointerA.next if pointerA else headB
        pointerB = pointerB.next if pointerB else headA
    return pointerA  

#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/intersection-of-two-linked-lists/
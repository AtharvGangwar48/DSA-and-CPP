class Node:
    def __init__(self, val=0):
        self.val = val
        self.prev = None
        self.next = None

class MyLinkedList:
    def __init__(self):
        self.head = Node(0)   
        self.tail = Node(0)  
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0
    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1
        curr = self.head.next
        for _ in range(index):
            curr = curr.next
        return curr.val
    def addAtHead(self, val: int) -> None:
        self._add(self.head, self.head.next, val)
    def addAtTail(self, val: int) -> None:
        self._add(self.tail.prev, self.tail, val)
    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.size:
            return
        curr = self.head
        for _ in range(index):
            curr = curr.next
        self._add(curr, curr.next, val)
    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        curr = self.head.next
        for _ in range(index):
            curr = curr.next
        self._remove(curr)
    def _add(self, prev, next, val):
        node = Node(val)
        node.prev = prev
        node.next = next
        prev.next = node
        next.prev = node
        self.size += 1
    def _remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1

#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/design-linked-list/
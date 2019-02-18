# 206. Reverse Linked List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    def print(self):
        print(self.val, end='')
        tmp = self
        while tmp.next:
            print("->", tmp.next.val, sep='', end='')
            tmp = tmp.next
        print()

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # # iterative
        # if not head:
        #     return head
        # last_node = head
        # next_node = head.next
        # head.next = None
        # while next_node:
        #     head = next_node
        #     next_node = head.next
        #     head.next = last_node
        #     last_node = head
        # return head

        # recursive
        def reverse(node):
            """
            :type node: ListNode
            :rtype head: ListNode, tail ListNode
            """
            if node.next:
                head, tail = reverse(node.next)
                tail.next = node
                return head, node
            else:
                return node, node
        
        if head:
            cur_head, cur_tail = reverse(head)
            cur_tail.next = None
            return cur_head
        else:
            return None

if __name__ == "__main__":
    s = Solution()
    
    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(3)
    d = ListNode(4)
    a.next = b
    b.next = c
    c.next = d

    s.reverseList(a).print()
        
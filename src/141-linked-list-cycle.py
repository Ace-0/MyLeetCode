# 141. Linked List Cycle


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None or head.next is None:
            return False
        low = head.next
        fast = low.next
        while low and fast:
            if low == fast:
                return True
            low = low.next
            fast = fast.next
            if not fast:
                return False
            fast = fast.next
        return False


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = 0

    ans = s.function(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
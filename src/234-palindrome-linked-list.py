# 234. Palindrome Linked List

import math


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        cnt = 0
        tmp = head
        while tmp:
            tmp = tmp.next
            cnt += 1
        if cnt <= 1:
            return True
        half = math.floor(cnt / 2)
        tmp = head
        while half:
            tmp = tmp.next
            half -= 1
        stack = []
        while head != tmp:
            stack.append(head.val)
            head = head.next
        if cnt % 2 == 1:
            head = head.next
        while head:
            if stack.pop() != head.val:
                return False
            head = head.next
        return True


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(2)
    d = ListNode(1)
    a.next = b
    b.next = c
    # c.next = d

    ans = s.isPalindrome(a)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
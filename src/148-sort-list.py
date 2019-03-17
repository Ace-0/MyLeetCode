# 148. Sort List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        return self.merge_sort(head)

    def merge_sort(self, head):
        head_a, head_b = self.split_into_two(head)
        if head_a and head_b:
            head_a = self.merge_sort(head_a)
            head_b = self.merge_sort(head_b)
        head_a = self.merge_two_list(head_a, head_b)
        return head_a

    def split_into_two(self, head):
        if not head:
            return None, None
        elif not head.next:
            return head, None
        else:
            slow = head
            fast = head
            while slow.next and fast.next and fast.next.next:
                slow = slow.next
                fast = fast.next.next

            head_a = head
            head_b = slow.next
            slow.next = None
            return head_a, head_b

    def merge_two_list(self, head_a, head_b):
        head = None
        tail = None
        while head_a and head_b:
            if head_a.val <= head_b.val:
                if tail:
                    tail.next = head_a
                    tail = tail.next
                else:
                    head = head_a
                    tail = head_a
                head_a = head_a.next
            else:
                if tail:
                    tail.next = head_b
                    tail = tail.next
                else:
                    head = head_b
                    tail = head_b
                head_b = head_b.next
        if not head:
            if head_a:
                head = head_a
            if head_b:
                head = head_b
        else:
            if head_a:
                tail.next = head_a
            if head_b:
                tail.next = head_b

        return head

    def print_list(self, head):
        if head:
            print(head.val, end='')
            head = head.next
            while head:
                print('->', head.val, sep='', end='')
                head = head.next
            print()


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    # -1->5->3->4->0
    head = ListNode(-1)
    head.next = ListNode(5)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(0)

    ans = s.sortList(head)
    s.print_list(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
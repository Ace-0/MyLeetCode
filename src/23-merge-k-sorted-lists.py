# 23. Merge k Sorted Lists

import heapq


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeKLists(self, lists: list) -> ListNode:
        # we need (lists[i].val, i) to keep a unique key for every element in priority queue
        que = [(lists[i].val, i, lists[i]) for i in range(len(lists)) if lists[i]]
        heapq.heapify(que)
        head = ListNode(0)
        tail = head
        while len(que):
            _, temp_idx, tmp_node = heapq.heappop(que)
            tail.next = tmp_node
            tail = tail.next
            if tmp_node.next:
                heapq.heappush(que, (tmp_node.next.val, temp_idx, tmp_node.next))
        return head.next

# import sys

# class Solution:
#     def mergeKLists(self, lists: list) -> ListNode:
#         head_node = None
#         tail_node = None
#         while True:
#             min_val = sys.maxsize
#             min_index = -1
#             for i in range(len(lists)):
#                 if lists[i] and lists[i].val <= min_val:
#                     min_val = lists[i].val
#                     min_index = i
#             if min_index == -1:
#                 break
#             if not head_node:
#                 head_node = lists[min_index]
#                 tail_node = lists[min_index]
#             else:
#                 tail_node.next = lists[min_index]
#                 tail_node = tail_node.next
#             lists[min_index] = lists[min_index].next
#         return head_node


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    # [
    #   1->4->5,
    #   1->3->4,
    #   2->6
    # ]
    head1 = ListNode(1)
    # head1.next = ListNode(4)
    # head1.next.next = ListNode(5)
    head2 = ListNode(0)
    # head2.next = ListNode(3)
    # head2.next.next = ListNode(4)
    head3 = ListNode(2)
    # head3.next = ListNode(6)
    lists = [head1, head2, head3]

    ans = s.mergeKLists(lists)

    print(ans.val, end='')
    ans = ans.next
    while ans:
        print('->', ans.val, sep='', end='')
        ans = ans.next
    print()

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
# 1030. Next Greater Node In Linked List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def nextLargerNodes(self, head: ListNode) -> list:
        arr = []
        while head:
            arr.append(head.val)
            head = head.next
        stack = []  # store (index, value)
        ans = [None] * len(arr)
        for i in range(len(arr)):
            while len(stack) and stack[-1][1] < arr[i]:
                top = stack.pop()
                ans[top[0]] = arr[i]
            stack.append((i, arr[i]))
        while len(stack):
            top = stack.pop()
            ans[top[0]] = 0
        return ans

# Input: [1,7,5,1,9,2,5,1]
# Output: [7,9,9,9,0,5,0,0]
# stack: [9 5]
# 1 7 5 1 9 2 5 1
# [7 9 9 9   5 ]


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = 0

    ans = s.nextLargerNodes(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))


# 102. Binary Tree Level Order Traversal

from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: 'TreeNode') -> 'List[List[int]]':
        if not root:
            return []
        order = []
        queue = deque([(root, 0)])
        while len(queue):
            cur_node, level = queue.popleft()
            if len(order) == level:
                order.append([cur_node.val])
            else:
                order[level].append(cur_node.val)

            if cur_node.left:
                queue.append((cur_node.left, level + 1))
            if cur_node.right:
                queue.append((cur_node.right, level + 1))
        return order


if __name__ == "__main__":
    import time
    start = time.clock()

    a = TreeNode(3)
    b = TreeNode(9)
    c = TreeNode(20)
    d = TreeNode(15)
    e = TreeNode(7)
    a.left = b
    a.right = c
    c.left = d
    c.right = e

    s = Solution()
    ans = s.levelOrder(a)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
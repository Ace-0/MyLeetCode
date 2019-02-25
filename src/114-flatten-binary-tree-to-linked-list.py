# 114. Flatten Binary Tree to Linked List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.rebuild(root)

    def rebuild(self, root):
        if not root:
            return None
        left_head = self.rebuild(root.left)
        right_head = self.rebuild(root.right)
        left_rear = left_head
        if left_rear:
            while left_rear.right:
                left_rear = left_rear.right
            left_rear.right = right_head
            root.right = left_head
        else:
            root.right = right_head
        root.left = None
        return root


if __name__ == "__main__":
    import time
    start = time.clock()

    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)
    e = TreeNode(5)
    f = TreeNode(6)
    a.left = b
    b.left = c
    b.right = d
    a.right = e
    e.right = f


    s = Solution()
    
    s.flatten(a)
    while a:
        print(a.val)
        a = a.right

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
# 101. Symmetric Tree

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: 'TreeNode') -> 'bool':
        if root:
            return self.helper(root.left, root.right)
        else:
            return True

    def helper(self, left_child, right_child):
        if not left_child and not right_child:
            return True
        elif (left_child and not right_child) or (not left_child and right_child):
            return False
        else:
            return left_child.val == right_child.val \
                   and self.helper(left_child.left, right_child.right) \
                   and self.helper(left_child.right, right_child.left)

#     1
#   2  3
#  3  2
#
#

if __name__ == "__main__":
    import time
    start = time.clock()

    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(2)
    d = TreeNode(3)
    e = TreeNode(4)
    f = TreeNode(4)
    g = TreeNode(3)
    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.left = f
    c.right = g

    s = Solution()
    ans = s.isSymmetric(a)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))

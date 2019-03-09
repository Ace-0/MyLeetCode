# 236. Lowest Common Ancestor of a Binary Tree


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # for a subtree, if:
        # 1. it contains both p and q:
        #     return their LCA
        # 2, it contains only p/q:
        #     return p/q
        # 3. it contains neither p and q:
        #     return None
        if root == p or root == q:
            return root
        elif not root:
            return None
        else:
            left = self.lowestCommonAncestor(root.left, p, q)
            right = self.lowestCommonAncestor(root.right, p, q)
            if left and right:
                return root
            elif left or right:
                return left or right
            else:
                return None


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    a = TreeNode(3)
    b = TreeNode(5)
    c = TreeNode(1)
    d = TreeNode(6)
    e = TreeNode(2)
    f = TreeNode(0)
    g = TreeNode(8)
    h = TreeNode(7)
    i = TreeNode(4)
    a.left = b
    b.left = d
    b.right = e
    e.left = h
    e.right = i
    a.right = c
    c.left = f
    c.right = g

    ans = s.lowestCommonAncestor(a, b, i)

    print(ans.val)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
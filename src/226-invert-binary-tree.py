# 226. Invert Binary Tree

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root:
            cur_left = self.invertTree(root.left)
            cur_right = self.invertTree(root.right)
            root.left = cur_right
            root.right = cur_left
        return root


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.function(0)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
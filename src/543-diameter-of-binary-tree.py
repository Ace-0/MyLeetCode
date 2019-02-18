# 543. Diameter of Binary Tree

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    diameter = 0
    def diameterOfBinaryTree(self, root: 'TreeNode') -> 'int':
        self.dfs(root)
        return self.diameter

    def dfs(self, root):
        if root:
            left_depth = self.dfs(root.left)
            right_depth = self.dfs(root.right)
            if left_depth + right_depth - 1 > self.diameter:
                self.diameter = left_depth + right_depth - 1

            return 1 + max(left_depth, right_depth)
        else:
            return 0

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.function(0)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
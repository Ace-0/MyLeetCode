# 617. Merge Two Binary Trees

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if t1 and t2:
            t = TreeNode(t1.val + t2.val)
            t.left = self.mergeTrees(t1.left, t2.left)
            t.right = self.mergeTrees(t1.right, t2.right)
            return t
        elif t1 and not t2:
            return self.clone_trees(t1)
        elif not t1 and t2:
            return self.clone_trees(t2)
        else:
            return None
    
    def clone_trees(self, root):
        if root:
            t = TreeNode(root.val)
            t.left = self.clone_trees(root.left)
            t.right = self.clone_trees(root.right)
            return t
        else:
            return None

def dfs(root):
    if root:
        print(root.val)
        if root.left:
            dfs(root.left)
        if root.right:
            dfs(root.right)

if __name__ == "__main__":
    import time
    start =time.clock()

    s = Solution()

    a1 = TreeNode(1)
    a2 = TreeNode(3)
    a3 = TreeNode(2)
    a4 = TreeNode(5)
    a1.left = a2
    a1.right = a3
    a2.left = a4

    b1 = TreeNode(2)
    b2 = TreeNode(1)
    b3 = TreeNode(3)
    b4 = TreeNode(4)
    b5 = TreeNode(7)
    b1.left = b2
    b1.right = b3
    b2.right = b4
    b3.right = b5

    ans = s.mergeTrees(a1, b1)
    

    end = time.clock()

    dfs(ans)
    print('Running time: %s Seconds'%(end-start))
        
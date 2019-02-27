# 105. Construct Binary Tree from Preorder and Inorder Traversal


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def buildTree(self, preorder: list, inorder: list) -> TreeNode:
        if len(preorder) == 0:
            return None

        root = TreeNode(preorder[0])
        root_idx = inorder.index(preorder[0])
        left_num = root_idx
        root.left = self.buildTree(preorder[1:left_num+1], inorder[:root_idx])
        root.right = self.buildTree(preorder[left_num+1:], inorder[root_idx+1:])
        return root


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]

    ans = s.buildTree(preorder, inorder)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
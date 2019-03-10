# 1003. Check If Word Is Valid After Substitutions


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def bstFromPreorder(self, preorder: list) -> TreeNode:
        return self.helper(preorder, 0, len(preorder) - 1)

    def helper(self, preorder, start, end):
        if start <= end:
            print(start, end)
            root = TreeNode(preorder[start])
            i = start + 1
            while i <= end and preorder[start] > preorder[i]:
                i += 1
            root.left = self.helper(preorder, start + 1, i - 1)
            root.right = self.helper(preorder, i, end)
            return root
        else:
            return None


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = [8,5,1,7,10,12]

    ans = s.bstFromPreorder(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))


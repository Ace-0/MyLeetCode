# 998. Maximum Binary Tree II
import sys
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        nums = self.destruct(root)
        nums.append(val)
        return self.construct(nums)

    def destruct(self, root):
        if root:
            return self.destruct(root.left) + [root.val] + self.destruct(root.right)
        else:
            return []

    def construct(self, nums):
        if len(nums):
            max = -sys.maxsize - 1
            max_i = -1
            for i in range(0, len(nums)):
                if nums[i] > max:
                    max_i = i
                    max = nums[i]
            root = TreeNode(max)
            root.left = self.construct(nums[:max_i])
            root.right = self.construct(nums[max_i + 1:])
            return root
        else:
            return None


if __name__ == "__main__":
    import time

    start = time.clock()

    a = TreeNode(5)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(1)
    a.left = b
    a.right = c
    b.right = d

    s = Solution()

    ans = s.insertIntoMaxTree(a, 4)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))



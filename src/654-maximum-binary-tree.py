# 654. Maximum Binary Tree

import sys

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: list[int]) -> TreeNode:
        if len(nums):
            max = -sys.maxsize - 1
            max_i = -1
            for i in range(0, len(nums)):
                if nums[i] > max:
                    max_i = i
                    max = nums[i]
            root = TreeNode(max)
            root.left = self.constructMaximumBinaryTree(nums[:max_i])
            root.right = self.constructMaximumBinaryTree(nums[max_i + 1:])
            return root
        else:
            return None

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    
    ans = s.function(0)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
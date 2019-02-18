# 538. Convert BST to Greater Tree

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def convertBST(self, root: 'TreeNode') -> 'TreeNode':
        max_sum = -1
        stack = []
        cur_node = root
        cur_sum = 0
        while len(stack) or cur_node:
            while cur_node:
                stack.append(cur_node)
                cur_node = cur_node.right

            top_node = stack.pop()
            top_node.val += cur_sum
            cur_sum = top_node.val
            cur_node = top_node.left
        return root



if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.function(0)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))

    #         4
    #      2      8               17
    #     1 3   6  9            23   9
    #          5 7            26
    #
    #         4
    #      2      8               17
    #     1 3   6              23   9
    #          5           26
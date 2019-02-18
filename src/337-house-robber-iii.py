# 337. House Robber III

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rob(self, root: 'TreeNode') -> 'int':
        return max(self.rob_a_tree(root))

    def rob_a_tree(self, root):
        if not root:
            return 0, 0
        l_child_yes, l_child_no = self.rob_a_tree(root.left)
        r_child_yes, r_child_no = self.rob_a_tree(root.right)
        cur_yes = l_child_no + r_child_no + root.val
        cur_no = max(l_child_yes, l_child_no) + max(r_child_yes, r_child_no)
        return cur_yes, cur_no

    #      3   4 + 1 + 3    4 + 5
    #     / \
    #4,4 4   5 5,1
    #   / \   \
    #  1   3   1
    #
    #

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.function(0)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))


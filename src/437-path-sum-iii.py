# 437. Path Sum III

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root: 'TreeNode', sum: 'int') -> 'int':
        return self.dfs_from_this_node(root, sum)

    def dfs_from_this_node(self, root, sum):
        if root:
            return self.dfs_from_remain(root, sum) + \
                   self.dfs_from_this_node(root.left, sum) + \
                   self.dfs_from_this_node(root.right, sum)
        else:
            return 0

    def dfs_from_remain(self, root, target):
        if root:
            cur_cnt = 1 if target == root.val else 0
            return cur_cnt + \
                   self.dfs_from_remain(root.left, target - root.val) + \
                   self.dfs_from_remain(root.right, target - root.val)
        else:
            return 0

#       10
#      /  \
#     5   -3
#    / \    \
#   3   2   11
#  / \   \
# 3  -2   1
if __name__ == "__main__":
    import time
    start = time.clock()

    vals = [10, 5, -3, 3, 2, 11, 3, -2, 1]
    nodes = []
    for v in vals:
        nodes.append(TreeNode(v))
    nodes[0].left = nodes[1]
    nodes[0].right = nodes[2]
    nodes[1].left = nodes[3]
    nodes[1].right = nodes[4]
    nodes[3].left = nodes[6]
    nodes[3].right = nodes[7]
    nodes[4].right = nodes[8]
    nodes[2].right = nodes[5]


    s = Solution()
    ans = s.pathSum(nodes[0], 8)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
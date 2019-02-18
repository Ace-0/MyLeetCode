# 988. Smallest String Starting From Leaf

from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    min_str = 'z' * 1000
    def smallestFromLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: str
        """
        self.dfs(root, '')
        return self.min_str

    def dfs(self, root, cur_str):
        cur_str += chr(97 + root.val)
        if root.left == None and root.right == None:
            if cur_str[::-1] < min_str:
                min_str = cur_str[::-1]
        else:
            if root.left:
                self.dfs(root.left, cur_str)
            if root.right:
                self.dfs(root.right, cur_str)
    # def build_tree(self, tree_arr):
    #     node_num = len(tree_arr)
    #     if node_num == 0:
    #         return None
        
    #     root = TreeNode(tree_arr[0])
    #     queue = deque([])
    #     queue.append(root)
    #     index = 0
    #     while len(queue):
    #         tmp_node = queue.popleft()
    #         index += 1
    #         if index < node_num and tree_arr[index]:
    #             tmp_node.left = TreeNode(tree_arr[index])
    #             queue.append(tmp_node.left)
    #         index += 1
    #         if index < node_num and tree_arr[index]:
    #             tmp_node.right = TreeNode(tree_arr[index])
    #             queue.append(tmp_node.right)
    #     return root

if __name__ == "__main__":
    import time
    start = time.clock()

    tree_arr = [0,1,2,3,4,3,4]

    s = Solution()
    ans = s.smallestFromLeaf(A, tree_arr)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
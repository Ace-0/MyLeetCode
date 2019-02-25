# 100. Same Tree

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        p_str = self.get_preorder_string(p)
        q_str = self.get_preorder_string(q)
        print(p_str)
        print(q_str)
        return p_str == q_str

    def get_preorder_string(self, root):
        preorder_str = ''
        stack = []
        stack.append(root)
        while len(stack):
            cur_node = stack.pop()
            if cur_node:
                preorder_str += ',' + str(cur_node.val)
                stack.append(cur_node.right)
                stack.append(cur_node.left)
            else:
                preorder_str += ',#'
        return preorder_str


if __name__ == "__main__":
    import time
    start = time.clock()

    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    a.left = b
    a.right = c

    o = TreeNode(1)
    p = TreeNode(2)
    q = TreeNode(3)
    o.left = p
    p.right = q

    s = Solution()
    
    ans = s.isSameTree(a, o)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
# 572. Subtree of Another Tree

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        s_str = self.get_preorder_string(s)
        t_str = self.get_preorder_string(t)
        return t in s

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

# class Solution:
#     def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
#         if self.is_same_tree(s, t):
#             return True
#         else:
#             if s and t:
#                 return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
#             else:
#                 return False
#
#     def is_same_tree(self, s, t):
#         if not s and not t:
#             return True
#         elif s and t:
#             return s.val == t.val \
#                    and self.is_same_tree(s.left, t.left) \
#                    and self.is_same_tree(s.right, t.right)
#         else:
#             return False


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    
    ans = s.function(0)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
# 297. Serialize and Deserialize Binary Tree

from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        que = deque([])
        data_str = ''
        que.append(root)
        while len(que):
            head = que.popleft()
            if head:
                data_str += str(head.val)
                que.append(head.left)
                que.append(head.right)
            else:
                data_str += ' '
            data_str += ','
        return data_str


    def deserialize(self, data_str):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        data = data_str.split(',')[:-1]
        n = len(data)
        if n == 0:
            return None
        nodes = [None] * n
        for i in range(n):
            if data[i] != ' ':
                nodes[i] = TreeNode(int(data[i]))
        que = deque([])
        que.append(nodes[0])
        i = 1
        while len(que):
            head = que.popleft()
            if head:
                if i >= n:
                    break
                head.left = nodes[i]
                que.append(nodes[i])
                i += 1
                if i >= n:
                    break
                head.right = nodes[i]
                que.append(nodes[i])
                i += 1

        return nodes[0]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

if __name__ == "__main__":
    import time
    start = time.clock()

    a = TreeNode(-1)
    b = TreeNode(0)
    c = TreeNode(1)
    d = TreeNode(4)
    e = TreeNode(5)
    f = TreeNode(6)
    g = TreeNode(7)
    a.left = b
    a.right = c
    c.left = d
    c.right = e
    d.left = f
    d.right = g

    codec = Codec()
    codes = codec.serialize(a)
    root = codec.deserialize(codes)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
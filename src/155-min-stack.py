# 155. Min Stack


class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.size = 0

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if self.size and x > self.stack[self.size - 1][1]:
            self.stack.append((x, self.stack[self.size - 1][1]))
        else:
            self.stack.append((x, x))
        self.size += 1

    def pop(self):
        """
        :rtype: None
        """
        self.stack.pop()
        self.size -= 1

    def top(self):
        """
        :rtype: int
        """
        if self.size:
            return self.stack[self.size - 1][0]
        else:
            return None

    def getMin(self):
        """
        :rtype: int
        """
        if self.size:
            return self.stack[self.size - 1][1]
        else:
            return None


if __name__ == "__main__":
    import time
    start = time.clock()

    minStack = MinStack()
    minStack.push(-2)
    minStack.push(0)
    minStack.push(-3)

    print(minStack.getMin())

    minStack.pop()
    print(minStack.top())

    print(minStack.getMin())

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
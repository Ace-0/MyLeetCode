# 461. Hamming Distance

class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        count = 0
        while x or y:
            if ((x & 1) ^ (y & 1)):
                count += 1
            x >>= 1
            y >>= 1
        return count


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    ans = s.hammingDistance(1, 4)

    end = time.clock()

    print("======================================")
    print("result: ", ans)
    print()
    print("---------------------------------------")
    print('Running time: %s ms'%((end-start) * 1000))
    print("======================================")
        
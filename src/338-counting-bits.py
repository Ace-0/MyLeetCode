# 338. Counting Bits

class Solution:
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        dp = [None] * (num + 1)
        dp[0] = 0
        base = 1
        for n in range(1, num + 1):
            if base * 2 == n:
                base *= 2
            dp[n] = dp[n - base] + 1
        return dp


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    ans = s.countBits(5)

    end = time.clock()

    print(ans)
    print('Running time: %s ms' % ((end - start) * 1000))

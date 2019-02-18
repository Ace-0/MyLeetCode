# 70. Climbing Stairs

class Solution:
    def climbStairs(self, n: 'int') -> 'int':
        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.climbStairs(3)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
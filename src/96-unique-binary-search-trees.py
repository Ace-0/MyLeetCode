# 96. Unique Binary Search Trees

class Solution:
    def numTrees(self, n: 'int') -> 'int':
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for node_num in range(2, n + 1):
            for left_num in range(0, node_num):
                dp[node_num] += dp[left_num] * dp[node_num - 1 - left_num]
        return dp[n + 1]

    # 1 2 3 4 5
    # 1 2 5 14 42
    # 1 4 10 28

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.numTrees(5)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
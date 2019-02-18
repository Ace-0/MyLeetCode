# 377. Combination Sum IV

class Solution:
    dp = []
    def combinationSum4(self, nums: 'List[int]', target: 'int') -> 'int':
        dp = [0] * (target + 1)
        for n in nums:
            if n <= target:
                dp[n] = 1

        for i in range(1, target + 1):
            for n in nums:
                if i - n >= 0:
                    dp[i] += dp[i - n]
        print(dp)
        return dp[target]


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.combinationSum4([3,4,5,6,7,8,9,10], 10)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
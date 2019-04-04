# 123. Best Time to Buy and Sell Stock III


class Solution:
    def maxProfit(self, prices: list) -> int:
        return 1


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = 0

    ans = s.function(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
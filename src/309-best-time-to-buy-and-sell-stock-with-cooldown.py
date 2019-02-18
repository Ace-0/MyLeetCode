# 309. Best Time to Buy and Sell Stock with Cooldown

class Solution:
    def maxProfit(self, prices: 'List[int]') -> 'int':
        size = len(prices)
        if size == 0:
            return 0
        s0 = [0] * size
        s1 = [0] * size
        s2 = [0] * size
        s0[0] = 0
        s1[0] = -prices[0]
        s2[0] = 0
        for i in range(1, size):
            s0[i] = max(s2[i - 1], s0[i - 1])
            s1[i] = max(s0[i - 1] - prices[i], s1[i - 1])
            s2[i] = s1[i - 1] + prices[i]
        return max(s0[size - 1], s2[size - 1])

    #            state machine
    #     --->        buy         ----
    # cool|   S0  ---------->  S1     | cool
    #     ---- ^              /   <---
    #      cool \       sell /
    #            \          /
    #             --- S2 <--
    #

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.maxProfit([1,2,3,0,2])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
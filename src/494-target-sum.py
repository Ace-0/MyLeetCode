# 494. Target Sum

# Solution:
#   P: subset of positive numbers
#   N: subset of negative numbers
#   sum(P) - sum(N) = target
#   sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
#   2 * sum(P) = target + sum(nums)

class Solution:
    def findTargetSumWays(self, nums: 'List[int]', S: 'int') -> 'int':
        offset = sum(nums)
        if S > offset or S < -offset:
            return 0
        cur_sums = [0] * (2 * offset + 1)
        cur_sums[0 + offset] = 1 # from the beginning
        for n in nums:
            next_sums = [0] * (2 * offset + 1)
            for i in range(0, len(cur_sums)):
                if cur_sums[i]:
                    next_sums[i + n] += cur_sums[i]
                    next_sums[i - n] += cur_sums[i]

            cur_sums = next_sums
        return cur_sums[offset + S]

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.findTargetSumWays([1, 1, 1, 1, 1], 3)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
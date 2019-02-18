# 198. House Robber

class Solution:
    def rob(self, nums: 'List[int]') -> 'int':
        prev_yes, prev_no = 0, 0
        for n in nums:
            tmp = prev_yes
            prev_yes = prev_no + n
            prev_no = max(tmp, prev_no)
        return max(prev_yes, prev_no)


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.rob([2, 7, 9, 3, 1])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))

    #     [2, 7, 9, 3, 1]
    # no:  0  2  7  11 11
    # yes: 2  7  11 10 12
        
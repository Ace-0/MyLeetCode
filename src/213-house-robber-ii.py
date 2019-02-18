# 213. House Robber II

class Solution:
    def rob(self, nums: 'List[int]') -> 'int':
        length = len(nums)
        if length == 1:
            return nums[0]

        return max(self.rob_some_houses(nums, 0, length - 1),
                   self.rob_some_houses(nums, 1, length))

    def rob_some_houses(self, houses, low, high):
        prev_yes, prev_no = 0, 0
        for h in houses[low:high]:
            tmp = prev_yes
            prev_yes = prev_no + h
            prev_no = max(tmp, prev_no)
        return max(prev_yes, prev_no)


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.function(0)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))

    #     [2, 7, 9, 3, 1, 2]
    # no:  0  2  7  11 11 12
    # yes: 2  7  11 10 12 13
    #
    #      2              100
    #   1     7          3   1
    #     3  9         1000  2
    #                      5
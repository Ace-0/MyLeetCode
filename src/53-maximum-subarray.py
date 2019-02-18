# 53. Maximum Subarray

class Solution:
    def maxSubArray(self, nums: 'List[int]') -> 'int':
        cur_sum = nums[0]
        max_sum = cur_sum
        for n in nums[1:]:
            cur_sum = max(cur_sum + n, n)
            if cur_sum > max_sum:
                max_sum = cur_sum
        return max_sum


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
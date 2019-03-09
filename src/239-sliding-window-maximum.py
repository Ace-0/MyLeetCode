# 239. Sliding Window Maximum


class Solution:
    def maxSlidingWindow(self, nums: list, k: int) -> list:
        if len(nums) == 0:
            return []
        right = k - 1
        cur_max = max(nums[0:right+1])
        cur_max_idx = nums[0:right+1].index(cur_max)
        ans = [cur_max]
        right += 1
        while right < len(nums):
            if nums[right] >= cur_max:
                cur_max = nums[right]
                cur_max_idx = right
            else:
                if cur_max_idx == right - k:
                    cur_max = max(nums[right-k+1:right+1])
                    cur_max_idx = nums[right-k+1:right+1].index(cur_max) + right - k + 1
            ans.append(cur_max)
            right += 1
        return ans


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = [9,10,9,-7,-4,-8,2,-6]
    k = 5

    ans = s.maxSlidingWindow(test_case, k)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))

    # Window position                Max
    # ---------------               -----
    # [1  3  -1] -3  5  3  6  7       3
    #  1 [3  -1  -3] 5  3  6  7       3
    #  1  3 [-1  -3  5] 3  6  7       5
    #  1  3  -1 [-3  5  3] 6  7       5
    #  1  3  -1  -3 [5  3  6] 7       6
    #  1  3  -1  -3  5 [3  6  7]      7
# 416. Partition Equal Subset Sum


class Solution:
    def canPartition(self, nums) -> bool:
        nums_sum = sum(nums)
        if nums_sum % 2 == 1 or len(nums) == 1:
            return False
        target = int(nums_sum / 2)
        cur_dp = [False] * (target + 1)
        cur_dp[0] = True
        for i in range(1, len(nums) + 1):
            next_dp = [False] * (target + 1)
            for j in range(target + 1):
                next_dp[j] = cur_dp[j] or cur_dp[j - nums[i - 1]]
            cur_dp = next_dp
            print(cur_dp)

        for i in range(len(nums) + 1):
            if cur_dp[target]:
                return True

        return False


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = [1, 2, 5]

    ans = s.canPartition(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
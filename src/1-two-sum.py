# 1. Two Sum

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        to_add = {}
        for i in range(0, len(nums)):
            if target - nums[i] in to_add:
                return [to_add[target - nums[i]], i]
            else:
                to_add[nums[i]] = i


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.twoSum([2, 7, 11, 15], 9)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
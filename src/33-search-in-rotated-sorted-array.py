# 33. Search in Rotated Sorted Array

import math


class Solution:
    def search(self, nums: list, target: int) -> int:
        if len(nums) == 0:
            return -1
        # binary search to find the smallest value
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + math.floor((right - left) / 2)
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
        min_index = left
        # binary search to find the target
        if target > nums[len(nums) - 1]:
            left = 0
            right = min_index - 1
        else:
            left = min_index
            right = len(nums) - 1
        while left <= right:
            mid = left + math.floor((right - left) / 2)
            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        return -1

# [4,5,6,7,0,1,2]
# [0,1,2] l=2,r=2
# [2]


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = [4,5,6,7,0,1,2]
    target = 0

    ans = s.search(test_case, target)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
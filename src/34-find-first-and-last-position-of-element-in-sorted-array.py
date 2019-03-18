# 34. Find First and Last Position of Element in Sorted Array

import math

class Solution:
    def searchRange(self, nums: list, target: int) -> list:
        # binary search
        left = 0
        right = len(nums) - 1
        if right == -1:
            return [-1, -1]
        while left < right:
            mid = left + math.floor((right - left) / 2)
            if target == nums[mid]:
                break
            elif target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        if left > right:
            return [-1, -1]
        elif left == right:
            if nums[left] != target:
                return [-1, -1]
            else:
                return [left, right]
        else:
            left = right = mid
            while left - 1 >= 0 and nums[left - 1] == target:
                left -= 1
            while right + 1 < len(nums) and nums[right + 1] == target:
                right += 1
            return [left, right]


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = [1]
    target = 3

    ans = s.searchRange(test_case, target)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
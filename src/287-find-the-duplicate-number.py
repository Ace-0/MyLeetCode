# 287. Find the Duplicate Number

class Solution:
    def findDuplicate(self, nums: 'List[int]') -> 'int':
        n = len(nums) - 1
        for i in range(0, n):
            while nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]:
                tmp = nums[i]
                nums[i] = nums[tmp - 1]
                nums[tmp - 1] = tmp
            if nums[i] != i + 1:
                return nums[i]
        return nums[n]


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.findDuplicate([1,1,2])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
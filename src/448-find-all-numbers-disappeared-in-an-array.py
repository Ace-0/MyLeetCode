# 448. Find All Numbers Disappeared in an Array

class Solution:
    def findDisappearedNumbers(self, nums: 'List[int]') -> 'List[int]':
        for i in range(len(nums)):
            while nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]:
                tmp = nums[i]
                nums[i] = nums[nums[i] - 1]
                nums[tmp - 1] = tmp
        ans = []
        for i, ele in enumerate(nums):
            if ele != i + 1:
                ans.append(i + 1)
        return ans


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.findDisappearedNumbers([4,3,2,7,8,2,3,1])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))

    # [4,3,2,7,8,2,3,1]
    # [7,3,2,4,8,2,3,1]
    # [1,2,3,4,3,2,7,8]
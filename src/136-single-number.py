# 136. Single Number

class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # res = 0
        # for num in nums:
        #     res ^= num
        # return res

        from functools import reduce
        return reduce(lambda x, y: x ^ y, nums)

if __name__ == "__main__":
    s = Solution()

    li = [4, 1, 2, 1, 2]

    ans = s.singleNumber(li)
    print(ans)
        
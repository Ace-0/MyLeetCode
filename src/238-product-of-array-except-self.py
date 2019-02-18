# 238. Product of Array Except Self

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        product_left, product_right, ans = [None] * length, [None] * length, [None] * length
        prod_l, prod_r = 1,  1
        for idx in range(0, length):
            prod_l *= nums[idx]
            product_left[idx] = prod_l
            prod_r *= nums[length - 1 - idx]
            product_right[length - 1 - idx] = prod_r

        for idx in range(0, length):
            left = product_left[idx - 1] if idx >= 1 else 1
            right = product_right[idx + 1] if idx <= length - 2 else 1
            ans[idx] = left * right
        return ans

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.productExceptSelf([1,2,3,4])
    print(ans)
    # [1,2,6,24]
    # [24,24,12,4]
    # [24,12,8,6]
    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
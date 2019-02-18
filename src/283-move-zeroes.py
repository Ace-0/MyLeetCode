# 283. Move Zeroes

class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # # Solution No.1
        # cnt = 0
        # length = len(nums)
        # idx = 0
        # while idx < (length - cnt):
        #     if nums[idx] == 0:
        #         nums.pop(idx)
        #         nums.append(0)
        #         cnt += 1
        #     else:
        #         idx += 1

        # # Solution No.2
        # nums[:] = ([value for value in nums if value != 0] + nums.count(0) * [0])

        # # Solution No.3
        slow = 0
        for fast,num in enumerate(nums):
            if num != 0:
                if slow < fast:
                    nums[slow] = num
                    nums[fast] = 0
                slow += 1
            print(nums)

if __name__ == "__main__":
    s = Solution()

    li = [0,1,0,3,12]
    s.moveZeroes(li)

    # print(li)
        
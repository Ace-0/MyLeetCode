# 169. Majority Element

class Solution:
    def majorityElement(self, nums: 'List[int]') -> 'int':
        major_ele = nums[0]
        cnt = 0
        for n in nums:
            if cnt == 0:
                cnt = 1
                major_ele = n
            elif major_ele == n:
                cnt += 1
            else:
                cnt -= 1
        return major_ele
        # ele2cnt = {}
        # half = len(nums)
        # max_cnt = 0
        # max_n = nums[0]
        # for n in nums:
        #     if n in ele2cnt:
        #         ele2cnt[n] += 1
        #         if ele2cnt[n] > half:
        #             return n
        #         if ele2cnt[n] > max_cnt:
        #             max_cnt = ele2cnt[n]
        #             max_n = n
        #     else:
        #         ele2cnt[n] = 1
        # return max_n


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.majorityElement([2,2,1,1,1,2,2])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
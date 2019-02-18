# 560. Subarray Sum Equals K

class Solution:
    def subarraySum(self, nums: 'List[int]', k: 'int') -> 'int':
        sum2cnt = {}
        cur_sum = 0
        k_cnt = 0
        for n in nums:
            cur_sum += n
            if cur_sum == k:
                k_cnt += 1
            if (cur_sum - k) in sum2cnt:
                k_cnt += sum2cnt[cur_sum - k]
            if cur_sum in sum2cnt:
                sum2cnt[cur_sum] += 1
            else:
                sum2cnt[cur_sum] = 1
        return k_cnt


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.subarraySum([1], 0)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
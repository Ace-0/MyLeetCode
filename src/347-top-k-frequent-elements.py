# 347. Top K Frequent Elements

class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        int_cnt_dict = {}
        for n in nums:
            if n not in int_cnt_dict:
                int_cnt_dict[n] = 1
            int_cnt_dict[n] += 1
        int_cnt_tuples = sorted(int_cnt_dict.items(), key=lambda x: x[1], reverse=True)

        return [t[0] for t in int_cnt_tuples[:k]]


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.topKFrequent([1,1,1,2,2,3], 2)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
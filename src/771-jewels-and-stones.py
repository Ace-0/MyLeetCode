# 771. Jewels and Stones

class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        stones = list(S)
        if not len(stones):
            return 0
        stones.sort()

        total_count = 0
        cur_count = 1
        last_ch = stones[0]
        for cur_ch in stones[1:]:
            if cur_ch == last_ch:
                cur_count += 1
            else:
                if J.count(last_ch):
                    total_count += cur_count
                last_ch = cur_ch
                cur_count = 1
        if J.count(last_ch):
            total_count += cur_count
        return total_count

if __name__ == "__main__":
    import time
    start =time.clock()

    s = Solution()

    ans = s.numJewelsInStones("ebd", "bbb")

    end = time.clock()

    print(ans)
    print('Running time: %s Seconds'%(end-start))
        
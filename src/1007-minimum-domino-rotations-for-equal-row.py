# 1003. Check If Word Is Valid After Substitutions

from collections import defaultdict


class Solution:
    def minDominoRotations(self, A: list, B: list) -> int:
        dom_num = len(A)
        top = defaultdict(int)
        bottom = defaultdict(int)
        top_max_num = 0
        bottom_max_num = 0
        top_max_cnt = 0
        bottom_max_cnt = 0
        for i in range(dom_num):
            top[A[i]] += 1
            if top[A[i]] > top_max_cnt:
                top_max_cnt = top[A[i]]
                top_max_num = A[i]
            bottom[B[i]] += 1
            if bottom[B[i]] > bottom_max_cnt:
                bottom_max_cnt = bottom[B[i]]
                bottom_max_num = B[i]
        flag1 = True
        flag2 = True
        for i in range(dom_num):
            if A[i] != top_max_num and B[i] != top_max_num:
                flag1 = False
            if A[i] != bottom_max_num and B[i] != bottom_max_num:
                flag2 = False
        if flag1 and flag2:
            return min(dom_num - top_max_cnt, dom_num - bottom_max_cnt)
        elif flag1:
            return dom_num - top_max_cnt
        elif flag2:
            return dom_num - bottom_max_cnt
        else:
            return -1


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    A = [2,1,1,1,2,2,2,1,1,2]
    B = [1,1,2,1,1,1,1,2,1,1]

    ans = s.minDominoRotations(A, B)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))


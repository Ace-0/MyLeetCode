# 1003. Check If Word Is Valid After Substitutions


class Solution:
    def largestSumAfterKNegations(self, A: list, K: int) -> int:
        diff = []
        neg_cnt = 0
        ori_sum = 0
        for i in range(0, len(A)):
            if A[i] < 0:
                neg_cnt += 1
            ori_sum += A[i]
            diff.append(-2 * A[i])
        diff.sort(reverse=True)
        if neg_cnt >= K:
            for i in range(0, K):
                ori_sum += diff[i]
        else:
            for i in range(0, neg_cnt):
                ori_sum += diff[i]
            if (K - neg_cnt) % 2 == 1 and diff[neg_cnt] != 0:
                x = abs(diff[neg_cnt - 1])
                y = abs(diff[neg_cnt])
                ori_sum -= x if x < y else y
        return ori_sum


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = [-8,3,-5,-3,-5,-2]
    # 16 10 10 6 4 -6
    # 3 -2:  -3 2  [-2]
    # 8 5 5 3 2   3
    K = 6

    ans = s.largestSumAfterKNegations(test_case, K)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))


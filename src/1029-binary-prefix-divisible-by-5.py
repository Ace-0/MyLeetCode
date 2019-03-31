# 1003. Binary Prefix Divisible By 5


class Solution:
    def prefixesDivBy5(self, A: list) -> list:
        ans = [None] * len(A)
        r = A[0]
        ans[0] = True if A[0] == 0 else False
        for i in range(1, len(A)):
            r = (r * 2 + A[i]) % 5
            ans[i] = True if r == 0 else False
        return ans


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = [0,1,1,1,1,1]

    ans = s.prefixesDivBy5(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))



# 1003. Check If Word Is Valid After Substitutions

import math


class Solution:
    def clumsy(self, N: int) -> int:
        if N == 1:
            return N
        elif N == 2:
            return N * (N - 1)
        elif N == 3:
            return math.floor(N * (N - 1) / (N - 2))
        elif N == 4:
            return math.floor(N * (N - 1) / (N - 2)) + (N - 3)
        else:
            res = math.floor(N * (N - 1) / (N - 2)) + (N - 3)
            N -= 4
            while N >= 4:
                res -= math.floor(N * (N - 1) / (N - 2))
                res += N - 3
                N -= 4
            if N == 1:
                res -= N
            elif N == 2:
                res -= N * (N - 1)
            elif N == 3:
                res -= math.floor(N * (N - 1) / (N - 2))
            else:
                pass
            return res


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = 4

    ans = s.clumsy(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))


# 1028. Convert to Base -2


class Solution:
    def baseNeg2(self, N: int) -> str:
        if N == 0:
            return '0'
        ans = ''
        q = N
        while q != 0:
            q, r = self.divide(q, -2)
            if r == 1:
                ans += '1'
            else:
                ans += '0'
        return ans[::-1]

    def divide(self, a, b):
        quotient = a // b
        remainder = a % b
        if remainder < 0:
            quotient += 1
            remainder -= b
        return quotient, remainder


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = 0

    ans = s.baseNeg2(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))



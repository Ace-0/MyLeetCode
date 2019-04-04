# 371. Sum of Two Integers


class Solution:
    def getSum(self, a: int, b: int) -> int:
        # 32 bits integer max
        MAX = 0x7FFFFFFF
        # mask to get last 32 bits
        mask = 0xFFFFFFFF
        # first time: get carry bits and different bits
        # other times: calculate (carry bits + different bits)
        # if carry bits(b) == 0, the result is different bits(a)
        while b:
            carry_bits = a & b  # carry bits
            a = (a ^ b) & mask  # different bits
            b = (carry_bits << 1) & mask
        return a if a <= MAX else ~(a ^ mask)


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    a = -1
    b = 1

    ans = s.getSum(a, b)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
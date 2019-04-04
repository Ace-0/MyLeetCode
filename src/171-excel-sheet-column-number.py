# 171. Excel Sheet Column Number


class Solution:
    def titleToNumber(self, s: str) -> int:
        base = 1
        number = 0
        for i in range(len(s) - 1, -1, -1):
            number += base * (ord(s[i]) - ord('A') + 1)
            base *= 26
        return number


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = 'AA'

    ans = s.titleToNumber(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
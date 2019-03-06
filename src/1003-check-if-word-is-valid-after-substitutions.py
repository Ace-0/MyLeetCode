# 1003. Check If Word Is Valid After Substitutions

class Solution:
    def isValid(self, S: str) -> bool:
        tempS = ""
        while tempS != S:
            tempS = S
            S = S.replace('abc', '')
        if tempS == '':
            return True
        else:
            return False


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = "aabcbc"

    ans = s.isValid(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))


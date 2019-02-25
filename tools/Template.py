class Solution:
    def function(self, args: 'type') -> 'type':
        return 1


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = 0

    ans = s.function(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
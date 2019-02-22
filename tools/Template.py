class Solution:
    def function(self, args: 'type') -> 'type':
        return 1


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    
    ans = s.function(0)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
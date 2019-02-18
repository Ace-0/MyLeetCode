# 647. Palindromic Substrings

class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        total_num = 0
        length = len(s)
        if length == 0:
            return 0

        # others
        low = high = 0
        while high <= length - 1:
            # successive
            while high + 1 < length and s[high + 1] == s[low]:
                high += 1
            while low - 1 > 0 and s[low - 1] == s[high]:
                low -= 1
            total_num += self.get_factorial(high - low + 1)

            radius = 1
            print(low, high, radius)
            while low - radius > 0 and high + radius < length and s[low - radius] == s[high + radius]:
                total_num += 1
                radius += 1
            
            high += 1
            low = high
        return total_num

    
    def get_factorial(self, n):
        n_sum = 0
        while n:
            n_sum += n
            n -= 1
        return n_sum

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.countSubstrings('aba')
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
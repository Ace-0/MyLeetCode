# 438. Find All Anagrams in a String

# Template: https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.

class Solution:
    def findAnagrams(self, s: str, p: str) -> list:
        p_len = len(p)
        demand = {}
        base = ord('a')
        for ch in p:
            if ch in demand:
                demand[ch] += 1
            else:
                demand[ch] = 1
        to_satisfied = len(demand)
        start = 0
        end = 0
        ans = []
        while end < len(s):
            ch = s[end]
            if ch in demand:
                demand[ch] -= 1
                if demand[ch] == 0:
                    to_satisfied -= 1

            while to_satisfied == 0:
                if end - start + 1 == p_len:
                    ans.append(start)
                # move start forward
                if s[start] in demand:
                    demand[s[start]] += 1
                    if demand[s[start]] > 0:
                        to_satisfied += 1
                start += 1
            end += 1
        return ans


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = ('cbaebabacd', 'abc')

    ans = s.findAnagrams(test_case[0], test_case[1])

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
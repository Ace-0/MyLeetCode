# 49. Group Anagrams

class Solution:
    def groupAnagrams(self, strs: 'List[str]') -> 'List[List[str]]':
        str2idx = {}
        ans = []
        for s in strs:
            s_sorted = ''.join(sorted(s))
            if s_sorted in str2idx:
                ans[str2idx[s_sorted]].append(s)
            else:
                str2idx[s_sorted] = len(ans)
                ans.append([s])
        return ans


if __name__ == "__main__":
    import time
    start = time.clock()

    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    s = Solution()
    ans = s.groupAnagrams(strs)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
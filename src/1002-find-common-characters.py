# 1002. Find Common Characters

from collections import defaultdict

class Solution:
    def commonChars(self, A: list) -> list:
        cnt = defaultdict(int)
        first = True
        for word in A:
            word_cnt = defaultdict(int)
            for ch in word:
                word_cnt[ch] += 1
            if first:
                first = False
                for k in word_cnt.keys():
                    cnt[k] = word_cnt[k]
            else:
                for k in cnt.keys():
                    if word_cnt[k] < cnt[k]:
                        cnt[k] = word_cnt[k]
        ans = []
        for k in cnt.keys():
            ans += [k] * cnt[k]
        return ans


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = ["cool","lock","cook"]

    ans = s.commonChars(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))


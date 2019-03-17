# 139. Word Break


class Solution:
    def wordBreak(self, s: str, wordDict: list) -> bool:
        dp = [False] * len(s)
        for i in range(len(s)):
            for word in wordDict:
                if s[i+1-len(word) : i+1] == word and (dp[i-len(word)] or i-len(word) == -1):
                    dp[i] = True
                    break
        return dp[-1]


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    # sss = "catsandog"
    # wordDict = ["cats", "dog", "sand", "and", "cat"]

    sss = "applepenapple"
    wordDict = ["apple", "pen"]

    ans = s.wordBreak(sss, wordDict)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
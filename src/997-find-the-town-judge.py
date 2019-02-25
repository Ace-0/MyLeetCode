# 997. Find the Town Judge

class Solution:
    def findJudge(self, N, trust) -> int:
        if N == 1 and len(trust) == 0:
            return 1
        be_trusted_cnt = {}
        trust_somebody = [False] * (N + 1)
        for t in trust:
            trust_somebody[t[0]] = True
            if t[1] in be_trusted_cnt:
                be_trusted_cnt[t[1]] += 1
            else:
                be_trusted_cnt[t[1]] = 1
        print(be_trusted_cnt)
        print(trust_somebody)
        for i in range(1, N + 1):
            if not trust_somebody[i] and i in be_trusted_cnt and be_trusted_cnt[i] == N - 1:
                return i
        return -1


if __name__ == "__main__":
    import time
    start = time.clock()
    s = Solution()
    ans = s.findJudge(1, [])
    print(ans)
    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
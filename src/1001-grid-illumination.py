# 1001. Grid Illumination

class Solution:
    def gridIllumination(self, N, lamps, queries):
        # 1.check: 4 ways
        # 2. shut down
        ans = []
        for que in queries:
            qi = que[0]
            qj = que[1]
            # 1 * qi + b1 = qj
            b1 = qj - qi
            # (-1) * qi + b2 = qj
            b2 = qj + qi
            lit = False
            for lam in lamps:
                li = lam[0]
                lj = lam[1]
                if qi == li \
                    or qj == lj \
                    or li * 1 + b1 == lj \
                    or li * (-1) + b2 == lj:
                    lit = True
                    ans.append(1)
                    break
            if not lit:
                ans.append(0)
            # turn off lamps
            i = 0
            while i < len(lamps):
                li = lamps[i][0]
                lj = lamps[i][1]
                if abs(li - qi) < 2 and abs(lj - qj) < 2:
                    lamps.pop(i)
                else:
                    i += 1
        return ans


if __name__ == "__main__":
    import time
    start = time.clock()
    s = Solution()
    ans = s.gridIllumination(5, [[0,0],[4,4]], [[1,1],[1,0]])
    print(ans)
    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
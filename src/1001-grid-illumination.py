# 1001. Grid Illumination

from collections import defaultdict


class Solution:
    def gridIllumination(self, N, lamps, queries):
        # 0. initialize
        x_lit = defaultdict(int)
        y_lit = defaultdict(int)
        tl_lit = defaultdict(int)  # top left to down right
        tr_lit = defaultdict(int)  # top right to down left
        positions = defaultdict(set)
        ans = []
        for lam in lamps:
            x, y = lam
            positions[x].add(y)
            x_lit[x] += 1
            y_lit[y] += 1
            tl_lit[x + y] += 1
            tr_lit[N - 1 + x - y] += 1
        # 1. check: 4 ways
        for que in queries:
            x, y = que
            if x_lit[x] or y_lit[y] or tl_lit[x + y] or tr_lit[N - 1 + x - y]:
                ans.append(1)
                # 2. turn off lamps
                for i in range(-1, 2):
                    for j in range(-1, 2):
                        if (y + j) in positions[x + i]:
                            positions[x + i].remove(y + j)
                            x_lit[x + i] -= 1
                            y_lit[y + j] -= 1
                            tl_lit[x + y] -= 1
                            tr_lit[N - 1 + x - y] -= 1
            else:
                ans.append(0)

        return ans


if __name__ == "__main__":
    import time
    start = time.clock()
    s = Solution()
    ans = s.gridIllumination(5, [[0,0],[4,4]], [[1,1],[1,0]])
    print(ans)
    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
# 1031. Number of Enclaves

from collections import deque


class Solution:
    def numEnclaves(self, A: list) -> int:
        m = len(A)
        if m == 0:
            return 0
        n = len(A[0])

        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

        for i in range(0, m):
            # left
            self.dfs(i, 0, A, directions, m, n)
            # right
            self.dfs(i, n - 1, A, directions, m, n)

        for j in range(0, n):
            # top
            self.dfs(0, j, A, directions, m, n)
            # bottom
            self.dfs(m - 1, j, A, directions, m, n)

        cnt = 0
        for i in range(m):
            for j in range(n):
                if A[i][j] == 1:
                    cnt += 1
        return cnt

    def dfs(self, x, y, A, directions, m, n):
        if 0 <= x < m \
                and 0 <= y < n \
                and A[x][y] == 1:
            A[x][y] = 0
            for d in directions:
                self.dfs(x + d[0], y + d[1], A, directions, m, n)

        # for i in range(0, m):
        #     # left
        #     if A[i][0] == 1:
        #         self.bfs(i, 0, A, directions, m, n)
        #     # right
        #     if A[i][n - 1] == 1:
        #         self.bfs(i, n - 1, A, directions, m, n)
        #
        # for j in range(0, n):
        #     # top
        #     if A[0][j] == 1:
        #         self.bfs(0, j, A, directions, m, n)
        #     # bottom
        #     if A[m - 1][j] == 1:
        #         self.bfs(m - 1, j, A, directions, m, n)
        #
        # cnt = 0
        # for i in range(m):
        #     for j in range(n):
        #         if A[i][j] == 1:
        #             cnt += 1
        # return cnt

    # def bfs(self, x, y, A, directions, m, n):
    #     que = deque([(x, y)])
    #     while len(que):
    #         head = que.popleft()
    #         A[head[0]][head[1]] = 0
    #         for dire in directions:
    #             next_x = head[0] + dire[0]
    #             next_y = head[1] + dire[1]
    #             if 0 <= next_x < m \
    #                     and 0 <= next_y < n \
    #                     and A[next_x][next_y] == 1:
    #                 que.append((next_x, next_y))

# [0,0,0,0],     [0,1,1,0],
# [1,0,1,0],     [0,0,1,0]
# [0,1,1,0],     [0,0,1,0]
# [0,0,0,0]]     [0,0,0,0]


if __name__ == "__main__":
    import time

    start = time.clock()

    s = Solution()

    test_case = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    # test_case = [[0, 1, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 0, 0]]
    ans = s.numEnclaves(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
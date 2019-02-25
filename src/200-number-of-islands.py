# 200. Number of Islands

from collections import deque

class Solution:
    def numIslands(self, grid) -> int:
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        island_cnt = 0
        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    island_cnt += 1
                    self.bfs(grid, i, j, m, n, directions)
        return island_cnt

    def bfs(self, grid, x, y, m, n, directions):
        queue = deque([])
        queue.append((x, y))
        grid[x][y] = '0'

        while len(queue):
            head = queue.popleft()
            cur_x = head[0]
            cur_y = head[1]
            for direct in directions:
                next_x = cur_x + direct[0]
                next_y = cur_y + direct[1]
                if 0 <= next_x < m \
                        and 0 <= next_y < n \
                        and grid[next_x][next_y] == '1':
                    grid[next_x][next_y] = '0'
                    queue.append((next_x, next_y))


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]

    ans = s.numIslands(test_case)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
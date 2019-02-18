# 64. Minimum Path Sum

class Solution:
    def minPathSum(self, grid: 'List[List[int]]') -> 'int':
        height = len(grid)
        width = len(grid[0])
        for i in range(1, height):
            grid[i][0] += grid[i - 1][0]
        for j in range(1, width):
            grid[0][j] += grid[0][j - 1]
        for i in range(1, height):
            for j in range(1, width):
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1])
        return grid[height - 1][width - 1]


if __name__ == "__main__":
    import time
    start = time.clock()

    grid = [
        [1, 3, 1],
        [1, 5, 1],
        [4, 2, 1]
    ]
    s = Solution()
    ans = s.minPathSum(grid)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
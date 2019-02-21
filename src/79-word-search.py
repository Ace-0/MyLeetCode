# 79. Word Search

class Solution:
    def exist(self, board: 'List[List[str]]', word: 'str') -> 'bool':
        directions = [[-1, 0], [0, -1], [1, 0], [0, 1]]
        visited = [[0] * len(board[0]) for row in range(0, len(board))]
        found = False
        for i in range(0, len(board)):
            for j in range(0, len(board[0])):
                if board[i][j] == word[0]:
                    visited[i][j] = 1
                    if self.dfs(i, j, board, word[1:], visited, directions):
                        return True
                    visited[i][j] = 0
        return False

    def dfs(self, cur_x, cur_y, board, word, visited, directions):
        if len(word) == 0:
            return True
        for dir in directions:
            next_x = cur_x + dir[0]
            next_y = cur_y + dir[1]
            if 0 <= next_x < len(board) and 0 <= next_y < len(board[0]) \
                and visited[next_x][next_y] == 0 \
                and board[next_x][next_y] == word[0]:
                visited[next_x][next_y] = 1
                if self.dfs(next_x, next_y, board, word[1:], visited, directions):
                    return True
                visited[next_x][next_y] = 0
        return False


if __name__ == "__main__":
    import time
    start = time.clock()

    board = [
        ['A', 'B', 'C', 'E'],
        ['S', 'F', 'C', 'S'],
        ['A', 'D', 'E', 'E']
    ]
    b = [["a","a"]]
    s = Solution()
    ans1 = s.exist(board, 'ABCCED')
    ans2 = s.exist(board, 'SEE')
    ans3 = s.exist(board, 'ABCB')
    print(ans1)
    print(ans2)
    print(ans3)
    ans = s.exist(b, 'a')
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        
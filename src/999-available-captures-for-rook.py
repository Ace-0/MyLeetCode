# 999. Available Captures for Rook

class Solution:
    def numRookCaptures(self, board) -> int:
        Ri = Rj = 0
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    Ri = i
                    Rj = j
        cnt = 0
        i, j = Ri - 1, Rj
        while i >= 0 and board[i][j] != 'B':
            if board[i][j] == 'p':
                cnt += 1
                break
            i -= 1

        i, j = Ri, Rj + 1
        while j < 8 and board[i][j] != 'B':
            if board[i][j] == 'p':
                cnt += 1
                break
            j += 1
        i, j = Ri + 1, Rj
        while i < 8 and board[i][j] != 'B':
            if board[i][j] == 'p':
                cnt += 1
                break
            i += 1
        i, j = Ri, Rj - 1
        while j >= 0 and board[i][j] != 'B':
            if board[i][j] == 'p':
                cnt += 1
                break
            j -= 1
        return cnt

if __name__ == "__main__":
    import time
    start = time.clock()
    s = Solution()
    ans = s.numRookCaptures([[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]])
    print(ans)
    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
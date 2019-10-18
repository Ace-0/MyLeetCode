// 529. Minesweeper


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		const vector<vector<int>> directions = { {1,-1},{ 1,0 },{ 1,1 },{ -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 } };
		const int rows = board.size();
		if (rows == 0)
			return board;
		const int cols = board[0].size();
		if (isInBound(click[0], click[1], rows, cols)) {
			reveal(click[0], click[1], board, rows, cols, directions);
		}
		return board;
	}
private:
	void reveal(int r, int c, vector<vector<char>>& board, const int rows, const int cols, const vector<vector<int>>& directions) {
		if (board[r][c] == 'M') {
			// Actually, we don't need this if condition in recursion.
			// It will only happen after the first click.
			board[r][c] = 'X';
			return;
		}
		else if (board[r][c] == 'E'){
			int adjMinesCnt = 0;
			for (const vector<int>& dir : directions) {
				adjMinesCnt = (isInBound(r + dir[0], c + dir[1], rows, cols) && board[r + dir[0]][c + dir[1]] == 'M') ? adjMinesCnt + 1 : adjMinesCnt;
			}
			if (adjMinesCnt == 0) {
				board[r][c] = 'B';
				for (const vector<int>& dir : directions) {
					if (isInBound(r + dir[0], c + dir[1], rows, cols))
						reveal(r + dir[0], c + dir[1], board, rows, cols, directions);
				}
			}
			else {
				board[r][c] = '0' + adjMinesCnt;
			}
		}
	}
	bool isInBound(int r, int c, const int rows, const int cols) {
		return (r >= 0 && r < rows && c >= 0 && c < cols);
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<vector<char>> board = {
//	//	{'B', '1', 'E', '1', 'B'},
//	//	{'B', '1', 'M', '1', 'B'},
//	//	{'B', '1', '1', '1', 'B'},
//	//	{'B', 'B', 'B', 'B', 'B'} 
//	//};
//	//vector<int> click = { 1, 2 };
//
//	vector<vector<char>> board = {
//	{'E', 'E', 'E', 'E', 'E'},
//	{'E', 'E', 'M', 'E', 'E'},
//	{'E', 'E', 'E', 'E', 'E'},
//	{'E', 'E', 'E', 'E', 'E'},
//	};
//	vector<int> click = { 3, 0 };
//
//	vector<vector<char>> ans = s.updateBoard(board, click);
//
//	for (vector<char> line : ans) {
//		for (char ch : line) {
//			cout << ch << " ";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}
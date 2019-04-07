// 289. Game of Life

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int height = board.size();
		if (height == 0)
			return;
		int width = board[0].size();
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				int neigh_alive = this->numOfLiveNeighbour(i, j, height, width, board);
				if (board[i][j] & 1) {
					// live cell
					if (neigh_alive < 2 || neigh_alive > 3)
						board[i][j] = 1;
					else
						board[i][j] = 3;
				}
				else {
					// dead cell
					if (neigh_alive == 3)
						board[i][j] = 2;
				}
			}
		}
		for (int i = 0; i < height; ++i)
			for (int j = 0; j < width; ++j)
				board[i][j] >>= 1;
	}
private:
	int numOfLiveNeighbour(int row, int col, int height, int width, vector<vector<int>>& board) {
		int count = 0;
		for (int i = row - 1; i <= row + 1; ++i)
			for (int j = col - 1; j <= col + 1; ++j)
				if (0 <= i
					&& i < height
					&& 0 <= j
					&& j < width
					&& !(i == row && j == col)
					&& board[i][j] & 1
					)
					count += 1;
		return count;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> board = {
//		{ 0, 1, 0 },
//		{ 0, 0, 1 },
//		{ 1, 1, 1 },
//		{ 0, 0, 0 }
//	};
//	
//	s.gameOfLife(board);
//
//	for (vector<int> row : board) {
//		for (int n : row) {
//			cout << n << ' ';
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
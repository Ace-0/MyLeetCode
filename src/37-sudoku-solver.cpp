// 37. Sudoku Solver


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> row_exist(9, vector<bool>(9, false));
		vector<vector<bool>> col_exist(9, vector<bool>(9, false));
		vector<vector<bool>> block_exist(9, vector<bool>(9, false));
		vector<pair<int, int>> empty_cells;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					row_exist[i][board[i][j] - '1'] = true;
					col_exist[j][board[i][j] - '1'] = true;
					int block_i = i / 3 * 3 + j / 3;
					block_exist[block_i][board[i][j] - '1'] = true;
				}
				else {
					empty_cells.push_back(pair<int, int>(i, j));
				}
			}
		}
		vector<int> path;
		vector<int> result;
		bool found = false;
		dfs(0, empty_cells, path, result, found, row_exist, col_exist, block_exist);
		vector<char> chars = { '.', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		for (int i = 0; i < empty_cells.size(); ++i) {
			board[empty_cells[i].first][empty_cells[i].second] = chars[result[i]];
		}
	}
private:
	void dfs(int cell_to_fill,
		vector<pair<int, int>>& empty_cells,
		vector<int>& path,
		vector<int>& result,
		bool& found,
		vector<vector<bool>>& row_exist,
		vector<vector<bool>>& col_exist,
		vector<vector<bool>>& block_exist) {
		if (found)
			return;
		if (cell_to_fill == empty_cells.size()) {
			for (int i = 0; i < path.size(); ++i)
				result.push_back(path[i]);
			found = true;
			return;
		}
		int r = empty_cells[cell_to_fill].first, c = empty_cells[cell_to_fill].second;
		int block_i = r / 3 * 3 + c / 3;
		for (int n = 1; n <= 9; ++n) {
			if (row_exist[r][n - 1] || col_exist[c][n - 1] || block_exist[block_i][n - 1])
				continue;
			row_exist[r][n - 1] = true;
			col_exist[c][n - 1] = true;
			block_exist[block_i][n - 1] = true;
			path.push_back(n);
			dfs(cell_to_fill + 1, empty_cells, path, result, found, row_exist, col_exist, block_exist);
			row_exist[r][n - 1] = false;
			col_exist[c][n - 1] = false;
			block_exist[block_i][n - 1] = false;
			path.pop_back();
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<char>> testcase = {
//		{'5','3','.','.','7','.','.','.','.'},
//		{'6','.','.','1','9','5','.','.','.'},
//		{'.','9','8','.','.','.','.','6','.'},
//		{'8','.','.','.','6','.','.','.','3'},
//		{'4','.','.','8','.','3','.','.','1'},
//		{'7','.','.','.','2','.','.','.','6'},
//		{'.','6','.','.','.','.','2','8','.'},
//		{'.','.','.','4','1','9','.','.','5'},
//		{'.','.','.','.','8','.','.','7','9'},
//	};
//	
//	s.solveSudoku(testcase);
//
//	for (int i = 0; i < 9; ++i) {
//		for (int j = 0; j < 9; ++j) {
//			cout << testcase[i][j] << ' ';
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}
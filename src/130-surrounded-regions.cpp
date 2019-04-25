// 130. Surrounded Regions


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();
		for (int i = 0; i < m; ++i) {
			if (board[i][0] == 'O')
				dfs(i, 0, m, n, board);
			if (board[i][n - 1] == 'O')
				dfs(i, n - 1, m, n, board);
			
		}
		for (int j = 0; j < n; ++j) {
			if (board[0][j] == 'O')
				dfs(0, j, m, n, board);
			if (board[m - 1][j] == 'O')
				dfs(m - 1, j, m, n, board);
		}
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (board[i][j] == 'Y')
					board[i][j] = 'O';
				else
					board[i][j] = 'X';
	}
private:
	void dfs(int i, int j, int m, int n, vector<vector<char>>& board) {
		board[i][j] = 'Y';
		if (i >= 1 && board[i - 1][j] == 'O')
			dfs(i - 1, j, m, n, board);
		if (i <= m - 2 && board[i + 1][j] == 'O')
			dfs(i + 1, j, m, n, board);
		if (j >= 1 && board[i][j - 1] == 'O')
			dfs(i, j - 1, m, n, board);
		if (j <= n - 2 && board[i][j + 1] == 'O')
			dfs(i, j + 1, m, n, board);
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	vector<vector<char>> testcase = {
//		{ 'X', 'X', 'X', 'X'},
//		{ 'X', 'O', 'O', 'X'},
//		{ 'X', 'X', 'O', 'X'},
//		{ 'X', 'O', 'X', 'X'},
//	};
//	
//	s.solve(testcase);
//
//	for (int i = 0; i < testcase.size(); ++i) {
//		for (int j = 0; j < testcase[0].size(); ++j) {
//			cout << testcase[i][j] << ' ';
//		}
//		cout << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}
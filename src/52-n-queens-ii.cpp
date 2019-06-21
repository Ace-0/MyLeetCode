// 52. N-Queens II


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		// place queens row by row, so we don't need row_exist
		vector<bool> col_exist(n, false);
		vector<bool> l_diag_exist(2 * n - 1, false), r_diag_exist(2 * n - 1, false);
		vector<int> placed(n, -1);
		int count = 0;
		dfs(0, placed, n, col_exist, l_diag_exist, r_diag_exist, count);
		return count;
	}
private:
	void dfs(int row, vector<int> placed, const int n, vector<bool>& col_exist,
		vector<bool>& l_diag_exist, vector<bool>& r_diag_exist, int& count) {
		if (row == n) {
			++count;
			return;
		}
		for (int col = 0; col < n; ++col) {
			if (!col_exist[col] && !l_diag_exist[row + col] && !r_diag_exist[row - col + n]) {
				placed[row] = col;
				col_exist[col] = true;
				l_diag_exist[row + col] = true;
				r_diag_exist[row - col + n] = true;
				dfs(row + 1, placed, n, col_exist, l_diag_exist, r_diag_exist, count);
				placed[row] = -1;
				col_exist[col] = false;
				l_diag_exist[row + col] = false;
				r_diag_exist[row - col + n] = false;
			}
		}
	}
};

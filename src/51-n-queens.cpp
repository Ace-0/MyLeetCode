// 51. N-Queens


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		// place queens row by row, so we don't need row_exist
		vector<bool> col_exist(n, false);
		vector<bool> l_diag_exist(2 * n - 1, false), r_diag_exist(2 * n - 1, false);
		vector<int> placed(n, -1);
		vector<vector<string>> results;
		dfs(0, placed, n, col_exist, l_diag_exist, r_diag_exist, results);
		return results;
	}
private:
	void dfs(int row, vector<int> placed, const int n, vector<bool>& col_exist,
		vector<bool>& l_diag_exist, vector<bool>& r_diag_exist, vector<vector<string>>& results) {
		if (row == n) {
			string empty_line;
			vector<string> sol(n, string(n, '.'));
			for (int r = 0; r < n; ++r)
				sol[r][placed[r]] = 'Q';
			results.push_back(sol);
			return;
		}
		for (int col = 0; col < n; ++col) {
			if (!col_exist[col] && !l_diag_exist[row + col] && !r_diag_exist[row - col + n]) {
				placed[row] = col;
				col_exist[col] = true;
				l_diag_exist[row + col] = true;
				r_diag_exist[row - col + n] = true;
				dfs(row + 1, placed, n, col_exist, l_diag_exist, r_diag_exist, results);
				placed[row] = -1;
				col_exist[col] = false;
				l_diag_exist[row + col] = false;
				r_diag_exist[row - col + n] = false;
			}
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	int testcase = 4;
//	
//	vector<vector<string>> ans = s.solveNQueens(testcase);
//
//	for (vector<string> sol : ans) {
//		cout << "[\n";
//		for (string line : sol)
//			cout << line << endl;
//		cout << "]\n";
//	}
//
//	system("pause");
//	return 0;
//}
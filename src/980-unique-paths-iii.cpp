// 980. Unique Paths III


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		int empty_num = 0, rows = grid.size(), cols = grid[0].size();
		int start_r = -1, start_c = -1;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (grid[i][j] == 0)
					++empty_num;
				else if (grid[i][j] == 1) {
					start_r = i;
					start_c = j;
				}
			}
		}
		int paths_count = 0;
		dfs(start_r - 1, start_c, empty_num, rows, cols, grid, paths_count);
		dfs(start_r + 1, start_c, empty_num, rows, cols, grid, paths_count);
		dfs(start_r, start_c - 1, empty_num, rows, cols, grid, paths_count);
		dfs(start_r, start_c + 1, empty_num, rows, cols, grid, paths_count);
		return paths_count;
	}

private:
	void dfs(int r, int c, int empty_num, const int rows, const int cols, vector<vector<int>>& grid, int& paths_count) {
		if (r == -1 || r == rows || c == -1 || c == cols
			|| grid[r][c] == -1 || grid[r][c] == 1)
			return;
		if (grid[r][c] == 2) {
			if (empty_num == 0)
				++paths_count;
			return;
		}
		grid[r][c] = -1;
		--empty_num;
		dfs(r - 1, c, empty_num, rows, cols, grid, paths_count);
		dfs(r + 1, c, empty_num, rows, cols, grid, paths_count);
		dfs(r, c - 1, empty_num, rows, cols, grid, paths_count);
		dfs(r, c + 1, empty_num, rows, cols, grid, paths_count);
		grid[r][c] = 0;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = {
//		{1, 0, 0, 0},
//		{0, 0, 0, 0},
//		{0, 0, 2, -1}
//	};
//	
//	int ans = s.uniquePathsIII(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 5263. Shift 2D Grid


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		int rows = grid.size(), cols = grid[0].size();
		for (int i = 0; i < k; ++i) {
			shiftOnce(grid, rows, cols);
		}
		return grid;
    }
private:
	void shiftOnce(vector<vector<int>>& grid, const int rows, const int cols) {
		vector<int> lastCol(rows, 0);
		for (int i = 0; i < rows; ++i)
			lastCol[i] = grid[i][cols - 1];
		for (int j = cols - 1; j >= 1; --j) {
			for (int i = 0; i < rows; ++i) {
				grid[i][j] = grid[i][j - 1];
			}
		}
		for (int i = 1; i < rows; ++i) {
			grid[i][0] = lastCol[i - 1];
		}
		grid[0][0] = lastCol[rows - 1];
	}
};

// int main() {
// 	Solution s = Solution();

// 	vector<vector<int>> grid = {
// 		{3,8,1,9},
// 		{19,7,2,5},
// 		{4,6,11,10},
// 		{12,0,21,13}
// 	};
// 	int k = 4;
// 	// vector<vector<int>> grid = {
// 	// 	{1,2,3},
// 	// 	{4,5,6},
// 	// 	{7,8,9}
// 	// };
// 	// int k = 1;

// 	vector<vector<int>> ans = s.shiftGrid(grid, k);

// 	return 0;
// }

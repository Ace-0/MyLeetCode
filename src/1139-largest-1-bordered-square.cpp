// 1139. Largest 1-Bordered Square


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> left2right(m, vector<int>(n, 0)), top2down(m, vector<int>(n, 0));
		// initialize left2right
		for (int r = 0; r < m; ++r) {
			int streak = 0;
			for (int c = 0; c < n; ++c) {
				if (grid[r][c] == 1)
					++streak;
				else
					streak = 0;
				left2right[r][c] = streak;
			}
		}
		// initialize top2down
		for (int c = 0; c < n; ++c) {
			int streak = 0;
			for (int r = 0; r < m; ++r) {
				if (grid[r][c] == 1)
					++streak;
				else
					streak = 0;
				top2down[r][c] = streak;
			}
		}

		// find 1-Bordered Square
		int result = 0;
		for (int r = 0; r < m; ++r) {
			for (int c = 0; c < n; ++c) {
				if (grid[r][c] == 1) {
					int edge_len = min(left2right[r][c], top2down[r][c]);
					while (edge_len > 0) {
						int top_right_r = r - edge_len + 1;
						int bottom_left_c = c - edge_len + 1;
						if (min(left2right[top_right_r][c], top2down[r][bottom_left_c]) >= edge_len) {
							result = max(result, edge_len * edge_len);
							break;
						}
						--edge_len;
					}
				}
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<vector<int>> grid = {
//	//	{ 1,1,1 },
//	//	{ 1,0,1 },
//	//	{ 1,0,1 },
//	//};
//	//vector<vector<int>> grid = {
//	//{ 1,0,1,1,1,1,1 },
//	//{ 1,1,1,1,0,0,1 },
//	//{ 0,1,1,1,1,0,1 },
//	//{ 0,1,1,1,0,0,1 },
//	//{ 1,0,1,1,1,1,1 },
//	//};
//	//vector<vector<int>> grid = { { 1 } };
//	vector<vector<int>> grid = {
//		{ 0,0,0 },
//		{ 0,0,0 },
//		{ 0,0,0 },
//	};
//
//	int ans = s.largest1BorderedSquare(grid);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}

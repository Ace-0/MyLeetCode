// 329. Longest Increasing Path in a Matrix


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int height = matrix.size();
		if (height == 0)
			return 0;
		int width = matrix[0].size();
		// len_from[i][j] means Longest Increasing Path start from matrix[i][j]
		// len_from[i][j] == 0 means the cell has not been visited
		vector<vector<int>> len_start_from(height, vector<int>(width, 0));

		int max_len = 1;
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				if (len_start_from[i][j] == 0) {
					dfs(i, j, height, width, max_len, len_start_from, matrix);
					max_len = max(max_len, len_start_from[i][j]);
				}
			}
		}
		return max_len;
	}

private:
	const vector<vector<int>> directions = {
		{ -1, 0 },
		{ 0, 1 },
		{ 1, 0 },
		{ 0, -1}
	};

	void dfs(int r, int c,
		int height, int width,
		int& max_len,
		vector<vector<int>>& len_start_from,
		const vector<vector<int>>& matrix)
	{
		len_start_from[r][c] = 1;
		for (vector<int> dir : directions) {
			int next_r = r + dir[0], next_c = c + dir[1];
			if (next_r >= 0
				&& next_r < height
				&& next_c >= 0
				&& next_c < width
				&& matrix[next_r][next_c] > matrix[r][c])
			{
				if (len_start_from[next_r][next_c] == 0) {
					// matrix[next_r][next_c] has not been visited
					dfs(next_r, next_c, height, width, max_len, len_start_from, matrix);
				}
				len_start_from[r][c] = max(len_start_from[next_r][next_c] + 1, len_start_from[r][c]);
			}
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<vector<int>> testcase =
//	//{
//	//	{ 9,9,4 },
//	//	{ 6,6,8 },
//	//	{ 2,1,1 }
//	//};
//	vector<vector<int>> testcase =
//	{
//		{ 3,4,5 },
//		{ 3,2,6 },
//		{ 2,2,1 }
//	};
//
//	int ans = s.longestIncreasingPath(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 417. Pacific Atlantic Water Flow


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> result;

		int rows = matrix.size();
		if (rows == 0)
			return result;
		int cols = matrix[0].size();

		vector<vector<int>> directions = { { -1, 0 }, { 0,1 }, { 1,0 }, { 0,-1 } };

		// dfs from Pacific
		vector<vector<bool>> p_visited(rows, vector<bool>(cols, false));
		for (int i = 0; i < rows; ++i)
			dfs(i, 0, rows, cols, directions, matrix, p_visited);
		for (int j = 0; j < cols; ++j)
			dfs(0, j, rows, cols, directions, matrix, p_visited);

		// dfs from Atlantic
		vector<vector<bool>> a_visited(rows, vector<bool>(cols, false));
		for (int i = 0; i < rows; ++i)
			dfs(i, cols - 1, rows, cols, directions, matrix, a_visited);
		for (int j = 0; j < cols; ++j)
			dfs(rows - 1, j, rows, cols, directions, matrix, a_visited);

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				if (p_visited[i][j] && a_visited[i][j])
					result.push_back(vector<int>{i, j});

		return result;
	}
private:
	void dfs(int i, int j, const int rows, const int cols, const vector<vector<int>>& directions, const vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
		visited[i][j] = true;
		for (vector<int> dir : directions) {
			int next_i = i + dir[0];
			int next_j = j + dir[1];
			if (next_i > -1 && next_i < rows
				&& next_j > -1 && next_j < cols
				&& !visited[next_i][next_j]
				&& matrix[next_i][next_j] >= matrix[i][j]
				)
				dfs(next_i, next_j, rows, cols, directions, matrix, visited);
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> matrix = {
//		{1,2,2,3,5},
//		{3,2,3,4,4},
//		{2,4,5,3,1},
//		{6,7,1,4,5},
//		{5,1,1,2,4}
//	};
//	
//	vector<vector<int>> ans = s.pacificAtlantic(matrix);
//
//	for (vector<int>& a : ans)
//		cout << "[" << a[0] << "," << a[1] << "] ";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
// 304. Range Sum Query 2D - Immutable


#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		m = matrix.size();
		if (m != 0) {
			n = matrix[0].size();
			accu_sum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
			for (int i = 1; i <= m; ++i)
				for (int j = 1; j <= n; ++j)
					accu_sum[i][j] = accu_sum[i][j - 1] + accu_sum[i - 1][j] - accu_sum[i - 1][j - 1] + matrix[i - 1][j - 1];
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return accu_sum[row2 + 1][col2 + 1] - accu_sum[row2 + 1][col1] - accu_sum[row1][col2 + 1] + accu_sum[row1][col1];
	}

private:
	vector<vector<int>> accu_sum;
	int m, n;
};



/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix* obj = new NumMatrix(matrix);
* int param_1 = obj->sumRegion(row1,col1,row2,col2);
*/

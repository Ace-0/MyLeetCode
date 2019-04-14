// 73. Set Matrix Zeroes


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool col_0_zero = false;
		for (int i = 0; i < matrix.size(); ++i) {
			if (matrix[i][0] == 0)
				col_0_zero = true;
			for (int j = 1; j < matrix[0].size(); ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < matrix.size(); ++i) {
			for (int j = 1; j < matrix[0].size(); ++j) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		// set row 0
		if (matrix[0][0] == 0)
			fill(matrix[0].begin(), matrix[0].end(), 0);
		// set col 0
		if (col_0_zero)
			for (int i = 0; i < matrix.size(); ++i)
				matrix[i][0] = 0;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = {
//		{0, 1, 2, 0},
//		{3, 4, 5, 2},
//		{1, 3, 1, 5} 
//	};
//	
//	s.setZeroes(testcase);
//
//	for (int i = 0; i < testcase.size(); ++i) {
//		for (int j = 0; j < testcase[0].size(); ++j) {
//			cout << testcase[i][j] << ' ';
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}
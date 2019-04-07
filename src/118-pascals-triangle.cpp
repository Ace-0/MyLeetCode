// 118. Pascal's Triangle

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> triangle;
		if (numRows == 0)
			return triangle;
		triangle.push_back(vector<int>(1, 1));
		int row = 0;
		while (row < numRows - 1) {
			row += 1;
			vector<int> cur_row(row + 1, 1);
			for (int i = 1; i < row; ++i)
				cur_row[i] = triangle[row - 1][i - 1] + triangle[row - 1][i];
			triangle.push_back(cur_row);
		}
		return triangle;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int testcase = 5;
//	
//	vector<vector<int>> triangle = s.generate(testcase);
//
//	for (vector<int> row : triangle) {
//		for (int n : row)
//			cout << n << ' ';
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}
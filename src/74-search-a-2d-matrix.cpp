// 74. Search a 2D Matrix


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int top = 0, down = matrix.size() - 1;
		int target_line = -1;
		while (top <= down) {
			int mid_line = top + (down - top) / 2;
			if (matrix[mid_line].empty())
				return false;
			if (target < matrix[mid_line].front())
				down = mid_line - 1;
			else if (target > matrix[mid_line].back())
				top = mid_line + 1;
			else {
				target_line = mid_line;
				break;
			}
		}
		if (target_line == -1)
			return false;
		if (target >= matrix[target_line].front() && target <= matrix[target_line].back()) {
			int left = 0, right = matrix[target_line].size() - 1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (target < matrix[target_line][mid])
					right = mid - 1;
				else if (target > matrix[target_line][mid])
					left = mid + 1;
				else
					return true;
			}
		}
		return false;
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<vector<int>> testcase = {
//	//	{}
//	//};
//	vector<vector<int>> testcase = {
//	{1,   3,  5,  7},
//	{10, 11, 16, 20},
//	{23, 30, 34, 50}
//	};
//	int target = 13;
//	
//	bool ans = s.searchMatrix(testcase, target);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
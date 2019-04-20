// 54. Spiral Matrix


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.size() == 0)
			return result;
		int top_bound = 0, down_bound = matrix.size() - 1;
		int left_bound = 0, right_bound = matrix[0].size() - 1;
		while (top_bound <= down_bound && left_bound <= right_bound) {
			for (int i = left_bound; i <= right_bound; ++i)
				result.push_back(matrix[top_bound][i]);
			for (int j = top_bound + 1; j <= down_bound; ++j)
				result.push_back(matrix[j][right_bound]);
			if (top_bound < down_bound)
				for (int i = right_bound - 1; i >= left_bound; --i)
					result.push_back(matrix[down_bound][i]);
			if (left_bound < right_bound)
				for (int j = down_bound - 1; j >= top_bound + 1; --j)
					result.push_back(matrix[j][left_bound]);
			++top_bound;
			--down_bound;
			++left_bound;
			--right_bound;
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = {
//		{ 1, 2, 3, 4 },
//		{ 5, 6, 7, 8 },
//		{ 9, 10, 11, 12 }
//	};
//	//vector<vector<int>> testcase = {
//	//	{ 3 },
//	//	{ 2 }
//	//};
//	
//	vector<int> ans = s.spiralOrder(testcase);
//
//	for (int n : ans)
//		cout << n << ' ';
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
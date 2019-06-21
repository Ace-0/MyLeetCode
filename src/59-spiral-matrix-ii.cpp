// 59. Spiral Matrix II


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		int num = 1, left = 0, right = n - 1, top = 0, down = n - 1;
		while (left <= right && top <= down) {
			for (int i = left; i <= right; ++i) {
				matrix[top][i] = num;
				++num;
			}
			for (int i = top + 1; i <= down; ++i) {
				matrix[i][right] = num;
				++num;
			}
			if (top < down) {
				for (int i = right - 1; i >= left; --i) {
					matrix[down][i] = num;
					++num;
				}
			}
			if (left < right) {
				for (int i = down - 1; i >= top + 1; --i) {
					matrix[i][left] = num;
					++num;
				}
			}
			++left;
			--right;
			++top;
			--down;
		}
		return matrix;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int k = 5;
//	
//	vector<vector<int>> ans = s.generateMatrix(k);
//
//	cout << "{" << endl;
//	for (vector<int> line : ans) {
//		cout << "\t{\t";
//		for (int num : line)
//			cout << num << "\t";
//		cout << "}" << endl;
//	}
//	cout << " }" << endl;
//
//	system("pause");
//	return 0;
//}
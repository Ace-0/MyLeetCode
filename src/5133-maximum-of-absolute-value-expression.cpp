// 5087. Letter Tile Possibilities


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
		int n = arr1.size();
		vector<vector<int>> formula_res(4, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			formula_res[0][i] = arr1[i] + arr2[i] + i;
			formula_res[1][i] = arr1[i] + arr2[i] - i;
			formula_res[2][i] = arr1[i] - arr2[i] + i;
			formula_res[3][i] = arr1[i] - arr2[i] - i;
		}
		int result = INT_MIN;
		for (int i = 0; i < 4; ++i) {
			int max_val = INT_MIN, min_val = INT_MAX;
			for (int j = 0; j < n; ++j) {
				max_val = max(max_val, formula_res[i][j]);
				min_val = min(min_val, formula_res[i][j]);
			}
			result = max(result, max_val - min_val);
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> arr1 = { 1,-2,-5,0,10 };
//	vector<int> arr2 = { 0,-2,-1,-7,-4 };
//	int ans = s.maxAbsValExpr(arr1, arr2);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}

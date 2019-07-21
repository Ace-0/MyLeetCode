// 5087. Letter Tile Possibilities


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int mctFromLeafValues(vector<int>& arr) {
		int n = arr.size();
		vector<vector<int>> memory(n, vector<int>(n, -1)), max_val(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			memory[i][i] = 0;
			int cur_max = 0;
			for (int j = i; j < n; ++j) {
				if (arr[j] > cur_max)
					cur_max = arr[j];
				max_val[i][j] = cur_max;
			}
		}
		for (int len = 2; len <= n; ++len) {
			for (int start = 0; start <= n - len; ++start) {
				int end = start + len - 1;
				memory[start][end] = INT_MAX;
				for (int i = start; i < end; ++i) {
					memory[start][end] = min(
						memory[start][end],
						max_val[start][i] * max_val[i + 1][end] + memory[start][i] + memory[i + 1][end]
					);
				}
			}
		}
		return memory[0][n - 1];
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = {6, 2, 4};
//
//	int ans = s.mctFromLeafValues(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}

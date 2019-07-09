// 174. Dungeon Game


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int rows = dungeon.size(), cols = dungeon[0].size();
		// min_required[i][j] means the minimal hp required to get to princess from dungeon[i][j]
		vector<vector<int>> min_required(rows + 1, vector<int>(cols + 1, INT_MAX));
		min_required[rows - 1][cols] = 1;
		min_required[rows][cols - 1] = 1;
		for (int r = rows - 1; r >= 0; --r) {
			for (int c = cols - 1; c >= 0; --c) {
				int next_min_required = min(min_required[r + 1][c], min_required[r][c + 1]) - dungeon[r][c];
				min_required[r][c] = next_min_required <= 0 ? 1 : next_min_required;
			}
		}
		return min_required[0][0];
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = {
//		{ -2, -3, 3 },
//		{ -5, -10, 1 },
//		{ 10, 30, -5 }
//	};
//	
//	int ans = s.calculateMinimumHP(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
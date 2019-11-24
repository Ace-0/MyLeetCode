// 1267. Count Servers that Communicate


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
		int rows = grid.size(), cols = grid[0].size();
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (grid[i][j] == 1) {
					++rowCount[i];
					++colCount[j];
				}
			}
		}
		int connectedCount = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) {
					++connectedCount;
				}
			}
		}
		return connectedCount;
    }
};

// int main() {
// 	Solution s = Solution();

// 	vector<vector<int>> test1 = { {1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
// 	vector<vector<int>> test2 = { {1,0},{1,1}};
// 	vector<vector<int>> test3 = { {1,0},{0,1}};

// 	int ans1 = s.countServers(test1);
// 	int ans2 = s.countServers(test2);
// 	int ans3 = s.countServers(test3);

// 	return 0;
// }

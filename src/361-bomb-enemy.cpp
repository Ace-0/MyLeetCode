// 361. Bomb Enemy


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int rows = grid.size();
		if (rows == 0) {
			return 0;
		}
		int cols = grid[0].size();
		if (cols == 0) {
			return 0;
		}
		vector<vector<int>> enemyCnt(rows, vector<int>(cols, 0));
		for (int i = 0; i < rows; ++i) {
			int enemyLeft = 0, enemyRight = 0;
			for (int j1 = 0, j2 = cols - 1; j1 < cols; ++j1, --j2) {
				if (grid[i][j1] == 'E') {
					++enemyLeft;
				} else if (grid[i][j1] == 'W') {
					enemyLeft = 0;
				} else {
					enemyCnt[i][j1] += enemyLeft;
				}
				if (grid[i][j2] == 'E') {
					++enemyRight;
				} else if (grid[i][j2] == 'W') {
					enemyRight = 0;
				} else {
					enemyCnt[i][j2] += enemyRight;
				}
			}
		}
		for (int j = 0; j < cols; ++j) {
			int enemyUp = 0, enemyDown = 0;
			for (int i1 = 0, i2 = rows - 1; i1 < rows; ++i1, --i2) {
				if (grid[i1][j] == 'E') {
					++enemyUp;
				} else if (grid[i1][j] == 'W') {
					enemyUp = 0;
				} else {
					enemyCnt[i1][j] += enemyUp;
				}
				if (grid[i2][j] == 'E') {
					++enemyDown;
				} else if (grid[i2][j] == 'W') {
					enemyDown = 0;
				} else {
					enemyCnt[i2][j] += enemyDown;
				}
			}
		}
		int maxCnt = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				maxCnt = max(maxCnt, enemyCnt[i][j]);
			}
		}
		return maxCnt;
    }
};

// int main() {
// 	Solution s = Solution();

// 	vector<vector<char>> grid = {
// 		{'0','E','0','0'},
// 		{'E','0','W','E'},
// 		{'0','E','0','0'}
// 	};
	
// 	int ans = s.maxKilledEnemies(grid);

// 	cout << ans << endl;

// 	return 0;
// }
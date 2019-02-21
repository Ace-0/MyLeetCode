class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0) {
			return 0;
		}
		int n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		int maxlength = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '0') {
					dp[i][j] == 0;
				}
				else {
					int left = j >= 1 ? dp[i][j - 1] : 0;
					int up = i >= 1 ? dp[i - 1][j] : 0;
					int upleft = (i >= 1 && j >= 1) ? dp[i - 1][j - 1] : 0;
					dp[i][j] = min(min(left, up), upleft) + 1;
					if (dp[i][j] > maxlength) {
						maxlength = dp[i][j];
					}
				}
			}
		}
		return maxlength * maxlength;
	}
};
// 1027. Longest Arithmetic Sequence


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestArithSeqLength(vector<int>& A) {
		// dp[i][j] + 1 means the longest length end at A[i] with difference j
		unordered_map<int, unordered_map<int, int>> dp;
		int max_len = 0;
		for (int i = 1; i < A.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i][A[i] - A[j]] = dp[j][A[i] - A[j]] + 1;
				max_len = max(max_len, dp[i][A[i] - A[j]]);
			}
		}
		return max_len + 1;
	}
};

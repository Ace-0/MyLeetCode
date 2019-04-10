// 516. Longest Palindromic Subsequence


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int s_len = s.length();
		if (s_len == 0)
			return 0;
		// dp[i][j] means the length of the Longest 
		// Palindromic Subsequence in s[i]s[i+1]...s[j]
		vector<vector<int>> dp(s_len, vector<int>(s_len, 0));
		// init
		for (int i = 0; i < s_len - 1; ++i) {
			dp[i][i] = 1;
			dp[i][i + 1] = (s[i] == s[i + 1]) ? 2 : 1;
		}
		dp[s_len - 1][s_len - 1] = 1;
		
		// states change, (length >= 3)
		for (int i = s_len - 3; i >= 0; --i) {
			for (int j = i + 2; j < s_len; ++j) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else {
					dp[i][j] = max(
						dp[i][j - 1],
						dp[i + 1][j]
					);
				}
			}
		}
		return dp[0][s_len - 1];
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "abcde";
//	
//	int ans = s.longestPalindromeSubseq(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
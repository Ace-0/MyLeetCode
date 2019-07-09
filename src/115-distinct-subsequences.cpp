// 115. Distinct Subsequences


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int s_len = s.length(), t_len = t.length();
		vector<vector<long>> dp(s_len, vector<long>(t_len, 0));
		for (int i = 0; i < s_len; ++i)
			if (s[i] == t[0])
				++dp[i][0];
		for (int j = 1; j < t_len; ++j) {
			char pre_ch = t[j - 1], cur_ch = t[j];
			long pre_end_cnt = 0;
			for (int i = 0; i < s_len; ++i) {
				if (s[i] == cur_ch)
					dp[i][j] += pre_end_cnt;
				if (s[i] == pre_ch)
					pre_end_cnt += dp[i][j - 1];
			}
		}
		int total_cnt = 0;
		for (int i = 0; i < s_len; ++i)
			total_cnt += dp[i][t_len - 1];
		return total_cnt;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string s_str = "rabbbit";
//	string t_str = "rabbit";
//	//string s_str = "babgbag";
//	//string t_str = "bag";
//	
//	int ans = s.numDistinct(s_str, t_str);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
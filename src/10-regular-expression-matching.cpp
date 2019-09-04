// 10. Regular Expression Matching

#include <iostream>
#include <vector>
#include <string>

using namespace std;

 // Top-Down DP
class Solution {
public:
    bool isMatch(string s, string p) {
		int s_len = s.length(), p_len = p.length();
		vector<vector<int>> cache(s_len + 1, vector<int>(p_len + 1, 0));  // -1, 0, 1 -> not match, unknown, match
		return dp(0, 0, s, p, s_len, p_len, cache);
    }
private:
	bool dp(int i, int j, const string& s, const string& p, const int s_len, const int p_len, vector<vector<int>>& cache) {
		if (cache[i][j] != 0)
			return cache[i][j] == 1 ? true : false;
		
		bool cur_result = false;
		if (j == p_len) {
			cur_result = (i == s_len);
		}
		else if (p_len - j > 1 && p[j + 1] == '*') {
			if (i == s_len) {
				cur_result = dp(i, j + 2, s, p, s_len, p_len, cache);
			}
			else if (s[i] == p[j] || p[j] == '.') {
				// if match, step over a s[0] or just ignore p[0:2]
				// we dont need to match s[0] with p[0:2], which means isMatch(s.substr(1), p.substr(2))
				// because it will be done in the next recursion by isMatch(s, p.substr(2)) -> isMatch(s.substr(1), p)
				cur_result = dp(i + 1, j, s, p, s_len, p_len, cache) || dp(i, j + 2, s, p, s_len, p_len, cache);
			}
			else
				cur_result = dp(i, j + 2, s, p, s_len, p_len, cache);  // dont match, have to ignore p[0:2]
		}
		else {
			if (i == s_len)
				cur_result = false;
			else
				cur_result = (s[i] == p[j] || p[j] == '.') ? dp(i + 1, j + 1, s, p, s_len, p_len, cache) : false;
		}
		cache[i][j] = cur_result ? 1 : -1;
		return cur_result;
	}
};

// // Bottom-Up DP
//class Solution {
//public:
//	bool isMatch(string s, string p) {
//		int s_len = s.length(), p_len = p.length();
//		vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));  // -1, 0, 1 -> not match, unknown, match
//		dp[s_len][p_len] = true;
//
//		for (int i = s_len; i >= 0; --i) {
//			for (int j = p_len - 1; j >= 0; --j) {
//				if (p_len - j > 1 && p[j + 1] == '*') {
//					if (i == s_len) {
//						dp[i][j] = dp[i][j + 2];
//					}
//					else if (s[i] == p[j] || p[j] == '.') {
//						dp[i][j] = dp[i + 1][j] || dp[i][j + 2];
//					}
//					else {
//						dp[i][j] = dp[i][j + 2];
//					}
//				}
//				else {
//					if (i == s_len)
//						dp[i][j] = false;
//					else
//						dp[i][j] = (s[i] == p[j] || p[j] == '.') ? dp[i + 1][j + 1] : false;
//				}
//			}
//		}
//		return dp[0][0];
//	}
//};

 //// Recursion
 //class Solution {
 //public:
 //    bool isMatch(string s, string p) {
 //		if (p.empty())
 //			return s.empty();
 //		if (p.length() >= 2 && p[1] == '*') {
 //			if (s.empty())
 //				return isMatch(s, p.substr(2));
 //			else if (s[0] == p[0] || p[0] == '.') {
 //				// if match, step over a s[0] or just ignore p[0:2]
 //				// we dont need to match s[0] with p[0:2], which means isMatch(s.substr(1), p.substr(2))
 //				// because it will be done in the next recursion by isMatch(s, p.substr(2)) -> isMatch(s.substr(1), p)
 //				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
 //			}
 //			else
 //				return isMatch(s, p.substr(2));  // dont match, have to ignore p[0:2]
 //		}
 //		else {
 //			if (s.empty())
 //				return false;
 //			else
 //				return (s[0] == p[0] || p[0] == '.') ? isMatch(s.substr(1), p.substr(1)) : false;
 //		}
 //    }
 //};

//int main() {
//	Solution s = Solution();
//
//	string s_str = "aab";
//	string p_str = "c*a*b";
//
//	bool ans = s.isMatch(s_str, p_str);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
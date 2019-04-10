// 5. Longest Palindromic Substring


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// expand from center 28ms 8.8MB
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return "";
		int longest_start = 0, longest_len = 1;
		for (int center = 0; center < s.length(); ++center) {
			int len = max(expendFromCenter(s, center, center),
						expendFromCenter(s, center, center + 1));
			if (len > longest_len) {
				longest_len = len;
				longest_start = center - (len - 1) / 2;
			}
		}
		return s.substr(longest_start, longest_len);
	}

private:
	int expendFromCenter(string& s, int left, int right) {
		while (left >= 0 && right < s.length() && s[left] == s[right]) {
			--left;
			++right;
		}
		return right - left - 1;
	}
};

//// DP 168ms 18.8MB
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		// dp[i][j] == true means s[i]s[i+1]...s[j] is a palindrome
//		int s_len = s.length();
//		if (s_len == 0)
//			return "";
//		vector<vector<bool>> dp(s_len, vector<bool>(s_len, false));
//		// init
//		int longest_start = 0, longest_len = 1;
//		for (int i = 0; i < s_len - 1; ++i) {
//			dp[i][i] = true;
//			if (s[i] == s[i + 1]) {
//				dp[i][i + 1] = true;
//				longest_start = i;
//				longest_len = 2;
//			}
//		}
//		dp[s_len - 1][s_len - 1] = true;
//		// states change, (length >= 3)
//		for (int i = s_len - 3; i >= 0; --i) {
//			for (int j = i + 2; j < s_len; ++j) {
//				if (s[i] == s[j] && dp[i + 1][j - 1]) {
//					dp[i][j] = true;
//					if (j - i + 1 > longest_len) {
//						longest_len = j - i + 1;
//						longest_start = i;
//					}
//				}
//			}
//		}
//		return s.substr(longest_start, longest_len);
//	}
//
//};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "cbbd";
//	
//	string ans = s.longestPalindrome(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
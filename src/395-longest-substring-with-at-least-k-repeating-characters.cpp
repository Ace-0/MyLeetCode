// 395. Longest Substring with At Least K Repeating Characters


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		return longestSplitSubstring(s, k, 0, s.length());
	}
private:
	int longestSplitSubstring(string s, int k, int left, int right) {
		vector<int> count(26, 0);
		for (int i = left; i < right; ++i)
			++count[s[i] - 'a'];
		int max_len = 0, sub_left = left;
		while (sub_left < right) {
			while (sub_left < right && count[s[sub_left] - 'a'] < k)
				++sub_left;
			if (sub_left == right)
				break;
			int sub_right = sub_left;
			while (sub_right < right && count[s[sub_right] - 'a'] >= k)
				++sub_right;
			if (sub_left == left && sub_right == right)
				return sub_right - sub_left;
			max_len = max(max_len, longestSplitSubstring(s, k, sub_left, sub_right));
			sub_left = sub_right;
		}
		return max_len;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "bbaaacbd";
//	
//	int ans = s.longestSubstring(testcase, 3);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
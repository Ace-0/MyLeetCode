// 159. Longest Substring with At Most Two Distinct Characters


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int len = s.length();
		if (len == 0)
			return 0;
		int start = 0, end = 1, distinct_cnt = 1;
		char ch_a = s[0], ch_b = s[0];
		int last_a = 0, last_b = 0;
		int max_len = 1;
		while (end < len) {
			if (s[end] != ch_a && s[end] != ch_b) {
				++distinct_cnt;
				if (distinct_cnt == 2) {
					ch_b = s[end];
					last_b = end;
					max_len = max(max_len, end - start + 1);
				}
				else {  // distinct_cnt == 3
					if (last_a < last_b) {
						start = last_a + 1;
						ch_a = s[end];
						last_a = end;
					}
					else {
						start = last_b + 1;
						ch_b = s[end];
						last_b = end;
					}
					--distinct_cnt;
				}
			}
			else {
				if (s[end] == ch_a)
					last_a = end;
				if (s[end] == ch_b)
					last_b = end;
				max_len = max(max_len, end - start + 1);
			}
			++end;
		}
		return max_len;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "abaccc";
//	
//	int ans = s.lengthOfLongestSubstringTwoDistinct(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 14. Longest Common Prefix


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		int len = 1;
		while (true) {
			if (len > strs[0].length())
				return strs[0].substr(0, len - 1);
			char cur_char = strs[0][len - 1];
			for (int str_num = 1; str_num < strs.size(); ++str_num) {
				if (len > strs[str_num].length() || strs[str_num][len - 1] != cur_char)
					return strs[str_num].substr(0, len - 1);
			}
			++len;
		}
		return "";
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<string> testcase = { "flower","flow","flight" };
//	
//	string ans = s.longestCommonPrefix(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
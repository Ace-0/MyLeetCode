// 402. Remove K Digits


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		int length = num.length();
		int required_len = length - k;
		string result = "";  // we can regard it as a stack
		int step = 0, max_step = k;
		for (int i = 0; i < length; ++i) {
			step = 0;
			max_step = length - i - (required_len - result.length());
			while (!result.empty() && num[i] < result.back() && step < max_step) {
				++step;
				result.pop_back();
			}
			result.push_back(num[i]);
		}
		result = result.substr(0, required_len);
		int start_pos = 0;
		while (start_pos < result.length() && result[start_pos] == '0')
			++start_pos;
		if (start_pos == result.length())
			return "0";
		else
			return result.substr(start_pos);
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "10";
//	int k = 2;
//	
//	string ans = s.removeKdigits(testcase, k);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 38. Count and Say


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string cur_str = "1";
		for (int i = 1; i < n; ++i) {
			string next_str = "";
			char pre = cur_str[0];
			int idx = 1, num_cnt = 1;
			while (idx < cur_str.length()) {
				if (cur_str[idx] != pre) {
					next_str += '0' + num_cnt;
					next_str += pre;
					pre = cur_str[idx];
					num_cnt = 1;
				}
				else {
					++num_cnt;
				}
				++idx;
			}
			next_str += '0' + num_cnt;
			next_str += pre;
			cur_str = next_str;
		}
		return cur_str;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int testcase = 6;
//	
//	string ans = s.countAndSay(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
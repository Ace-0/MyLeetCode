// 388. Longest Absolute File Path


#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthLongestPath(string input) {
		stack<MyStruct> stk;
		int i = 0, cur_level = 0, cur_str_len = 0, cur_total_len = 0, max_len = 0;
		bool is_file = false;
		input += '\n';  // dummy tail
		while (i < input.length()) {
			if (input[i] == '\n') {
				if (cur_level != 0)
					++cur_str_len;  // add a '/' for current string
				stk.push(MyStruct(cur_str_len, cur_level));
				cur_total_len += cur_str_len;
				if (is_file)
					max_len = max(max_len, cur_total_len);

				// reset all variables
				cur_str_len = 0;
				cur_level = 0;
				is_file = false;

				++i;
				while (input[i] == '\t') {
					++cur_level;
					++i;
				}
				while (!stk.empty() && cur_level <= stk.top().level) {
					cur_total_len -= stk.top().length;
					stk.pop();
				}
			}
			else {
				if (input[i] == '.')
					is_file = true;
				++cur_str_len;
				++i;
			}
		}
		return max_len;
	}
private:
	struct MyStruct {
		int length;
		int level;
		MyStruct(int len, int lev) : length(len), level(lev) {}
	};
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
//	
//	int ans = s.lengthLongestPath(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
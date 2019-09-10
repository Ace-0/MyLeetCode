// 301. Remove Invalid Parentheses


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		string path = "";
		unordered_set<string> result_set;
		int max_len = 0;
		dfs(0, 0, path, max_len, s, s.length(), result_set);
		vector<string> result(result_set.begin(), result_set.end());
		return result;
	}
private:
	void dfs(int start, int left_cnt, string& path, int& max_len, const string& full_str, const int full_len, unordered_set<string>& result_set) {
		if (start == full_len) {
			if (left_cnt == 0 && path.length() >= max_len) {
				if (path.length() > max_len) {
					result_set.clear();
					max_len = path.length();
				}
				result_set.insert(path);
			}
			return;
		}
		int ori_start = start;
		while (start < full_len && full_str[start] != '(' && full_str[start] != ')') {
			path += full_str[start];
			++start;
		}
		if (start != full_len) {
			dfs(start + 1, left_cnt, path, max_len, full_str, full_len, result_set);
			if (full_str[start] == '(') {
				path.push_back('(');
				dfs(start + 1, left_cnt + 1, path, max_len, full_str, full_len, result_set);
				path.pop_back();
			}
			else {
				if (left_cnt != 0) {
					path.push_back(')');
					dfs(start + 1, left_cnt - 1, path, max_len, full_str, full_len, result_set);
					path.pop_back();
				}
			}
		}
		else {
			dfs(start, left_cnt, path, max_len, full_str, full_len, result_set);
		}
		while (start > ori_start) {
			path.pop_back();
			--start;
		}

	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "()())()";
//	
//	vector<string> ans = s.removeInvalidParentheses(testcase);
//
//	for (const string& str : ans)
//		cout << "\"" << str << "\"" << endl;
//
//	system("pause");
//	return 0;
// }
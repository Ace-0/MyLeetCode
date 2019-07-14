// 282. Expression Add Operators


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> results;
		
		for (int end = 0; end < num.length(); ++end) {
			string cur_num_str = num.substr(0, end + 1);
			long cur_num_val = stol(cur_num_str);
			if (to_string(cur_num_val).size() != cur_num_str.size())
				break;  // zeroes at front
			dfs(num, end + 1,
				cur_num_str, cur_num_val,
				cur_num_val,
				target, results);
		}
		return results;
	}

private:
	void dfs(string& total_str, int start,
				string expr_str, long expr_val,
				int mult_val,
				int target, vector<string>& results) {
		if (start == total_str.length()) {
			if (expr_val == target)
				results.push_back(expr_str);
			return;
		}
		for (int end = start; end < total_str.length(); ++end) {
			string cur_num_str = total_str.substr(start, end - start + 1);
			long cur_num_val = stol(cur_num_str);
			if (to_string(cur_num_val).size() != cur_num_str.size())
				break;  // zeroes at front
			dfs(total_str, end + 1,
				expr_str + "+" + cur_num_str, expr_val + cur_num_val,
				cur_num_val,
				target, results);
			dfs(total_str, end + 1,
				expr_str + "-" + cur_num_str, expr_val - cur_num_val,
				-cur_num_val,
				target, results);
			dfs(total_str, end + 1,
				expr_str + "*" + cur_num_str, expr_val - mult_val + mult_val * cur_num_val,
				mult_val * cur_num_val,
				target, results);
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "123";
//	int target = 6;
//	
//	vector<string> ans = s.addOperators(testcase, target);
//
//	cout << "[ ";
//	for (string str : ans)
//		cout << "\"" << str << "\" ";
//	cout << "]" << endl;
//
//	system("pause");
//	return 0;
//}
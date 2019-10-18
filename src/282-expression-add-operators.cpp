// 282. Expression Add Operators


#include <iostream>
#include <vector>
#include <string>

using namespace std;

//class Solution {
//public:
//	vector<string> addOperators(string num, int target) {
//		vector<string> results;
//		
//		for (int end = 0; end < num.length(); ++end) {
//			string cur_num_str = num.substr(0, end + 1);
//			long cur_num_val = stol(cur_num_str);
//			if (to_string(cur_num_val).size() != cur_num_str.size())
//				break;  // zeroes at front
//			dfs(num, end + 1,
//				cur_num_str, cur_num_val,
//				cur_num_val,
//				target, results);
//		}
//		return results;
//	}
//
//private:
//	void dfs(string& total_str, int start,
//				string expr_str, long expr_val,
//				int mult_val,
//				int target, vector<string>& results) {
//		if (start == total_str.length()) {
//			if (expr_val == target)
//				results.push_back(expr_str);
//			return;
//		}
//		for (int end = start; end < total_str.length(); ++end) {
//			string cur_num_str = total_str.substr(start, end - start + 1);
//			long cur_num_val = stol(cur_num_str);
//			if (to_string(cur_num_val).size() != cur_num_str.size())
//				break;  // zeroes at front
//			dfs(total_str, end + 1,
//				expr_str + "+" + cur_num_str, expr_val + cur_num_val,
//				cur_num_val,
//				target, results);
//			dfs(total_str, end + 1,
//				expr_str + "-" + cur_num_str, expr_val - cur_num_val,
//				-cur_num_val,
//				target, results);
//			dfs(total_str, end + 1,
//				expr_str + "*" + cur_num_str, expr_val - mult_val + mult_val * cur_num_val,
//				mult_val * cur_num_val,
//				target, results);
//		}
//	}
//	};

class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		string init_str = "";
		for (int end = 0; end < num.length(); ++end) {
			if (num[0] == '0' && end > 0)
				continue;
			init_str += num[end];
			long num_val = stol(init_str);
			add_an_operator(num, end + 1, init_str, true, num_val, num_val, target, result);
		}
		return result;
	}
private:
	void add_an_operator(const string& str, int start, string cur_str, bool add_or_minus, long str_val, long total_value, int target, vector<string>& result) {
		if (start == str.length()) {
			if (total_value == target) {
				result.push_back(cur_str);
				return;
			}
		}
		// [start, end] is the next number string
		string cur_num_str = "";
		for (int i = start; i < str.length(); ++i) {
			if (str[start] == '0' && i > start)
				continue;
			cur_num_str += str[i];
			long cur_num_val = stol(cur_num_str);
			// +
			add_an_operator(str, i + 1, cur_str + "+" + cur_num_str, true, cur_num_val, total_value + cur_num_val, target, result);
			// -
			add_an_operator(str, i + 1, cur_str + "-" + cur_num_str, false, cur_num_val, total_value - cur_num_val, target, result);
			// *
			if (add_or_minus)
				add_an_operator(str, i + 1, cur_str + "*" + cur_num_str, add_or_minus, str_val * cur_num_val, total_value - str_val + str_val * cur_num_val, target, result);
			else
				add_an_operator(str, i + 1, cur_str + "*" + cur_num_str, add_or_minus, str_val * cur_num_val, total_value + str_val - str_val * cur_num_val, target, result);
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "2147483648";
//	long target = 0 - 2147483648;
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
// 224. Basic Calculator


#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> num_stack;
		stack<char> op_stack;

		int i = 0, j = 0;
		while (i < s.length()) {
			if (s[i] >= '0' && s[i] <= '9') {
				int j = i;
				while (j < s.length() && s[j] >= '0' && s[i] <= '9')
					++j;
				num_stack.push(stoi(s.substr(i, j - i)));
				i = j;
			}
			else if (s[i] == ' ') {
				++i;
			}
			else if (s[i] == '(') {
				op_stack.push(s[i]);
				++i;
			}
			else if (s[i] == ')') {
				while (!op_stack.empty() && op_stack.top() != '(') {
					int sub_result = get_sub_result(num_stack, op_stack);
					num_stack.push(sub_result);
				}
				op_stack.pop();
				++i;
			}
			else {
				if (op_stack.empty() || op_stack.top() == '(') {
					op_stack.push(s[i]);
				}
				else {
					while (!op_stack.empty() && op_stack.top() != '(') {
						int sub_result = get_sub_result(num_stack, op_stack);
						num_stack.push(sub_result);
					}
					op_stack.push(s[i]);
				}
				++i;
			}
		}
		while (!op_stack.empty()) {
			int sub_result = get_sub_result(num_stack, op_stack);
			num_stack.push(sub_result);
		}
		return num_stack.empty() ? 0 : num_stack.top();
	}

private:
	int get_sub_result(stack<int>& num_stack, stack<char>& op_stack) {
		char op = op_stack.top();
		op_stack.pop();
		int b = num_stack.top();
		num_stack.pop();
		int a = num_stack.top();
		num_stack.pop();
		if (op == '+')
			return a + b;
		else
			return a - b;
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	string testcase = "(1+(4+5+2)-3)+(6+8)";
//	
//	int ans = s.calculate(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
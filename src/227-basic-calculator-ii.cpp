// 227. Basic Calculator II


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> num_stack;
		stack<char> op_stack;
		unordered_map<char, int> priority({ {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} });

		int i = 0, j = 0;
		while (i < s.length()) {
			if (s[i] >= '0' && s[i] <= '9') {
				int j = i;
				while (j < s.length() && s[j] >= '0' && s[i] <= '9')
					++j;
				num_stack.push(string_to_int(s.substr(i, j - i)));
				i = j;
			}
			else if (s[i] == ' ') {
				++i;
			}
			else {
				if (op_stack.empty() || priority[s[i]] > priority[op_stack.top()]) {
					op_stack.push(s[i]);
				}
				else {
					while (!op_stack.empty() && priority[s[i]] <= priority[op_stack.top()]) {
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
		int result = 0;
		switch (op)
		{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		default:
			break;
		}
		return result;
	}

	int string_to_int(string str) {
		int result = 0;;
		for (char ch : str)
			result = result * 10 + (ch - '0');
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = " 3+5 / 2 ";
//	
//	int ans = s.calculate(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
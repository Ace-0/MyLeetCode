// 150. Evaluate Reverse Polish Notation


#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> num_stack;
		for (string str : tokens) {
			if (str[str.length() - 1] >= '0' && str[str.length() - 1] <= '9') {
				num_stack.push(stoi(str));
			}
			else {
				int b = num_stack.top();
				num_stack.pop();
				int a = num_stack.top();
				num_stack.pop();
				int result;
				if (str == "+")
					result = a + b;
				else if (str == "-")
					result = a - b;
				else if (str == "*")
					result = a * b;
				else
					result = a / b;
				num_stack.push(result);
			}
		}
		return num_stack.top();
	}
};

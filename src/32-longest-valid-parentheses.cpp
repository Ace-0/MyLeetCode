class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.length() < 2)
			return 0;
		stack<int> stk;
		int max_length = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				if (stk.empty())
					stk.push(i);
				else
					if (s[stk.top()] == '(')
						stk.pop();
					else
						stk.push(i);
			}
		}
		int left = 0, right = s.length();
		while (!stk.empty()) {
			left = stk.top();
			max_length = right - left - 1 > max_length ? right - left - 1 : max_length;
			right = left;
			stk.pop();
		}
		max_length = right - 0 > max_length ? right - 0 : max_length;
		return max_length;
	}
};

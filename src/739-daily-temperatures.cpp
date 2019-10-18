// 739. Daily Temperatures


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> result(n, 0);
		stack<int> stk;
		for (int i = T.size() - 1; i >= 0; --i) {
			if (stk.empty()) {
				result[i] = 0;
			}
			else {
				while (!stk.empty() && T[stk.top()] <= T[i]) {
					stk.pop();
				}
				if (stk.empty()) {
					result[i] = 0;
				}
				else {
					result[i] = stk.top() - i;
				}
			}
			stk.push(i);
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 73, 74, 75, 71, 69, 72, 76, 73 };
//	
//	vector<int> ans = s.dailyTemperatures(testcase);
//
//	for (int n : ans)
//		cout << n << " ";
//	cout << endl;
//
//	return 0;
//}
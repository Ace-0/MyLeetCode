// 1047. Remove All Adjacent Duplicates In String


#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

class Solution {
public:
	string removeDuplicates(string S) {
		stack<int> stk;
		for (int i = S.length() - 1; i >= 0; --i) {
			if (stk.empty() || stk.top() != S[i]) {
				stk.push(S[i]);
			}
			else {
				stk.pop();
			}
		}
		S.clear();
		while (!stk.empty()) {
			S += stk.top();
			stk.pop();
		}
		return S;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "abbaca";
//
//	string ans = s.removeDuplicates(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}

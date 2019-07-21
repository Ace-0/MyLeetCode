// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		vector<int> result;
		int A_left = 0, B_left = 0;
		for (char p : seq) {
			if (p == '(') {
				if (A_left < B_left) {
					++A_left;
					result.push_back(0);
				}
				else {
					++B_left;
					result.push_back(1);
				}
			}
			else {
				if (A_left < B_left) {
					--B_left;
					result.push_back(1);
				}
				else {
					--A_left;
					result.push_back(0);
				}
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "()(())()";
//	// ()()   ()()
//	// ()()() ()
//
//
//	vector<int> ans = s.maxDepthAfterSplit(testcase);
//
//	cout << "[ ";
//	for (int n : ans)
//		cout << n << " ";
//	cout << "]" << endl;
//
//	system("pause");
//	return 0;
//}

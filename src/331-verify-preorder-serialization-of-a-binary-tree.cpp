// 331. Verify Preorder Serialization of a Binary Tree


#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// using in/out degrees
class Solution {
public:
	bool isValidSerialization(string preorder) {
		int in_degrees = -1, out_degrees = 0;
		preorder += ',';  // so we wont miss the last node
		for (int i = 0; i < preorder.size(); ++i) {
			if (preorder[i] == ',') {
				in_degrees += 1;
				if (in_degrees > out_degrees)
					return false;
				if (preorder[i - 1] != '#')
					out_degrees += 2;
			}
		}
		return in_degrees == out_degrees;
	}
};

//// using stack
//class Solution {
//public:
//	bool isValidSerialization(string preorder) {
//		stack<char> stk;
//		bool is_number = false;
//		preorder += ',';  // so we wont miss the last node
//		for (char ch : preorder) {
//			if (ch == ',') {
//				if (is_number)
//					stk.push('n');  // 'n' means a number
//			}
//			else if (ch == '#') {
//				is_number = false;
//				while (!stk.empty() && stk.top() == '#') {
//					stk.pop();
//					if (!stk.empty())
//						stk.pop();
//					else
//						return false;
//				}
//				stk.push('#');
//			}
//			else {
//				is_number = true;
//			}
//		}
//		return stk.size() == 1 && stk.top() == '#';
//	}
//};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "9,#,92,#,#";
//	
//	bool ans = s.isValidSerialization(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
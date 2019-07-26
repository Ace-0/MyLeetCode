// 1081. Smallest Subsequence of Distinct Characters


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string smallestSubsequence(string text) {
		vector<int> remain(26, 0);
		vector<bool> exist(26, false);
		for (int i = 0; i < text.length(); ++i)
			++remain[text[i] - 'a'];
		
		string result = "";
		for (int i = 0; i < text.length(); ++i) {
			if (!exist[text[i] - 'a']) {
				while (!result.empty() && text[i] < result.back() && remain[result.back() - 'a'] > 0) {
					exist[result.back() - 'a'] = false;
					result.pop_back();
				}
				result.push_back(text[i]);
				exist[text[i] - 'a'] = true;
			}
			--remain[text[i] - 'a'];
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "cdadabcc";
//
//	string ans = s.smallestSubsequence(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}

// 131. Palindrome Partitioning


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<string> path;
		vector<vector<string>> result;
		dfs(0, s, path, result);
		return result;
	}

	void dfs(int left, string& str, vector<string>& path, vector<vector<string>>& result) {
		if (left == str.size()) {
			result.push_back(path);
			return;
		}
		for (int right = left; right <= str.length() - 1; ++right) {
			if (isPalindrome(left, right, str)) {
				path.push_back(str.substr(left, right - left + 1));
				dfs(right + 1, str, path, result);
				path.pop_back();
			}
		}
	}

	bool isPalindrome(int left, int right, string& str) {
		while (left < right) {
			if (str[left] != str[right])
				return false;
			++left;
			--right;
		}
		return true;
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	string testcase = "aab";
//	
//	vector<vector<string>> ans = s.partition(testcase);
//
//	for (vector<string> vec : ans) {
//		for (string str : vec) {
//			cout << str << ' ';
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}
// 125. Valid Palindrome


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0, right = s.length() - 1;
		while (left < right) {
			while (left < right && !is_alphanumeric(s[left]))
				++left;
			while (left < right && !is_alphanumeric(s[right]))
				--right;
			if (s[left] >= 'A' && s[left] <= 'Z')
				s[left] += 32;
			if (s[right] >= 'A' && s[right] <= 'Z')
				s[right] += 32;
			if (s[left] != s[right]) {
				return false;
			}
			else {
				++left;
				--right;
			}
		}
		return true;
	}
private:
	bool is_alphanumeric(char ch) {
		return ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "011";
//	
//	int ans = s.isPalindrome(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
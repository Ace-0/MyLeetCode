// 6. ZigZag Conversion


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		vector<vector<char>> lines(numRows, vector<char>());
		int x = 0;
		while (x < s.length()) {
			for (int i = 0; i < numRows && x < s.length(); ++i, ++x) {
				lines[i].push_back(s[x]);
			}
			for (int i = numRows - 2; i >= 1 && x < s.length(); --i, ++x) {
				lines[i].push_back(s[x]);
			}
		}
		string result = "";
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j < lines[i].size(); ++j) {
				result.push_back(lines[i][j]);
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "PAYPALISHIRING";
//	int k = 4;
//	
//	string ans = s.convert(testcase, k);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 387. First Unique Character in a String

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> indexes(26, -1);
		for (int i = 0; i < s.size(); ++i) {
			if (indexes[s[i] - 'a'] == -1) {  // first time
				indexes[s[i] - 'a'] = i;      // save the index
			}
			else {
				indexes[s[i] - 'a'] = -2;    // -2 means duplicate
			}
		}
		int min_index = s.size();
		for (int i = 0; i < 26; ++i)
			if (indexes[i] >= 0 && indexes[i] < min_index)
				min_index = indexes[i];
		return min_index == s.size() ? -1 : min_index;
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	string testcase = "loveleetcode";
//	
//	int ans = s.firstUniqChar(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
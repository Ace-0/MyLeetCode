// 567. Permutation in String


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> required(26, 0);
		for (char ch : s1)
			++required[ch - 'a'];
		int start = 0, end = 0;
		while (end < s2.length()) {
			--required[s2[end] - 'a'];
			if (required[s2[end] - 'a'] == -1) {
				while (s2[start] != s2[end]) {
					++required[s2[start] - 'a'];
					++start;
				}
				++start;
				required[s2[end] - 'a'] = 0;
			}
			if (end - start + 1 == s1.length())
				return true;
			++end;
		}
		return false;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string s1 = "biayp", s2 = "ainwkckifykxlribaypk";
//	
//	bool ans = s.checkInclusion(s1, s2);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
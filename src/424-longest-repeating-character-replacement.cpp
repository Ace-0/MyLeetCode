// 424. Longest Repeating Character Replacement


#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
	int characterReplacement(string s, int k) {
		int max_len = 0;
		for (char ch = 'A'; ch <= 'Z'; ++ch) {
			// repeating '{ch}'
			int k_left = k, start = 0, end = 0;
			while (end < s.length()) {
				if (s[end] != ch) {
					if (k_left > 0)
						--k_left;
					else {
						while (start < end && s[start] == ch)
							++start;
						++start;
						if (start == end)
							start = end + 1;
					}
				}
				++end;
				max_len = end - start > max_len ? end - start : max_len;
			}
		}
		return max_len;
	}
};

//int main() {
//	Solution s = Solution();
//
//	//string testcase = "IMNJJTRMJEGMSOLSCCQICIHLQIOGBJAEHQOCRAJQMBIBATGLJDTBNCPIFRDLRIJHRABBJGQAOLIKRLHDRIGERENNMJSDSSMESSTR";
//	string testcase = "ABAA";
//
//	int ans = s.characterReplacement(testcase, 0);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
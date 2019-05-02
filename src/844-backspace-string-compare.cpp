// 844. Backspace String Compare


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int i = S.length() - 1, j = T.length() - 1;
		int s_back = 0, t_back = 0;
		while (i >= 0 && j >= 0) {
			if (S[i] != '#' && T[j] != '#') {
				if (S[i] != T[j])
					return false;
				--i;
				--j;
			}
			else {
				if (S[i] == '#') {
					s_back = 1;
					--i;
					while (s_back > 0 && i >= 0) {
						if (S[i] == '#')
							++s_back;
						else
							--s_back;
						--i;
					}
				}
				if (T[j] == '#') {
					t_back = 1;
					--j;
					while (t_back > 0 && j >= 0) {
						if (T[j] == '#')
							++t_back;
						else
							--t_back;
						--j;
					}
				}
			}
		}
		while (i >= 0 && S[i] == '#') {
			s_back = 1;
			--i;
			while (s_back > 0 && i >= 0) {
				if (S[i] == '#')
					++s_back;
				else
					--s_back;
				--i;
			}
		}
		while (j >= 0 && T[j] == '#') {
			t_back = 1;
			--j;
			while (t_back > 0 && j >= 0) {
				if (T[j] == '#')
					++t_back;
				else
					--t_back;
				--j;
			}
		}
		if (i >= 0 || j >= 0)
			return false;
		return true;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int ans = s.backspaceCompare(
//		"isfcow#",
//		"isfcog#w#");
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 161. One Edit Distance


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		int s_len = s.length(), t_len = t.length();
		if (abs(s_len - t_len) > 1)
			return false;
		if (s_len > t_len)
			return isOneEditDistance(t, s);

		bool edited = false;
		int i = 0, j = 0;
		while (i < s_len) {
			if (s[i] != t[j]) {
				if (!edited) {
					if (s_len < t_len)
						++j;
					else if (s_len > t_len)
						++i;
					else {
						++i;
						++j;
					}

					edited = true;
				}
				else {
					return false;
				}
			}
			else {
				++i;
				++j;
			}

		}
		return edited || j == t_len - 1;
	}
};

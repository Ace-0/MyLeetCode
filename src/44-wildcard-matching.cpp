// 44. Wildcard Matching


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int si = 0, pi = 0, p_star = -1, s_star_end;
		while (si < s.length()) {
			if ((pi < p.length() && p[pi] == '?') || (s[si] == p[pi])) {
				++si;
				++pi;
			}
			else if (pi < p.length() && p[pi] == '*') {
				p_star = pi;
				++pi;
				s_star_end = si;
			}
			else if (p_star != -1) {
				pi = p_star + 1;
				++s_star_end;
				si = s_star_end;
			}
			else {
				return false;
			}
		}
		while (pi < p.length() && p[pi] == '*')
			++pi;
		return pi == p.length();
	}
};

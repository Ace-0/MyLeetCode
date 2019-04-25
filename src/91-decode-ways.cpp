// 91. Decode Ways


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0 || s[0] == '0')
			return 0;
		int iso_cnt = 1, comb_cnt = 0, tmp = 0;
		for (int i = 1; i < s.length(); ++i) {
			tmp = iso_cnt;
			if (s[i] == '0') {
				iso_cnt = 0;
				if (s[i - 1] == '1' || s[i - 1] == '2')
					comb_cnt = tmp;
				else
					comb_cnt = 0;
			}
			else if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
				iso_cnt = iso_cnt + comb_cnt;
				comb_cnt = tmp;
			}
			else {
				iso_cnt = iso_cnt + comb_cnt;
				comb_cnt = 0;
			}
		}
		return iso_cnt + comb_cnt;
	}
};

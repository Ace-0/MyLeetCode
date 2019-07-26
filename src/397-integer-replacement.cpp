// 397. Integer Replacement


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
		int rpl_cnt = 0;
		while (n != 1) {
			if (n & 1 == 0)
				n >>= 1;
			else if ((n >> 1) & 1 == 0 || n == 3)
				--n;
			else
				++n;
			++rpl_cnt;
		}
		return rpl_cnt;
	}
};

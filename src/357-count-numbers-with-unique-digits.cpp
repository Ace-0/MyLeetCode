// 357. Count Numbers with Unique Digits


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		/*
			num_length  unique_cnt  from
			0           0           don't exist
			1           10          0,1,2,...,9
			2           9*9         [xy], x from 1,2,...,9 and y from 0,1,...,9 excluding x
			3           9*9*8       [xyz], z from 0,1,...,9 excluding x and y
			4           9*9*8*7     ...
			5           9*9*8*7*6   ...
			6           9*9*8*7*6*5 ...
			7           9*9*8*...*4 ...
			8           9*9*8*...*3 ...
			9           9*9*8*...*2 ...
			10          9*9*8*...*1 ...
			11          0           don't exist
			12          0           don't exist
			...         0           don't exist
		*/
		if (n == 0)
			return 1;
		if (n > 10)
			return 0;
		int accu_cnt = 10, pre = 9, avail_digit_cnt = 9;
		for (int len = 2; len <= n; ++len) {
			accu_cnt += pre * avail_digit_cnt;
			pre *= avail_digit_cnt;
			--avail_digit_cnt;
		}
		return accu_cnt;
	}
};

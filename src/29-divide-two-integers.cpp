// 29. Divide Two Integers


#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}
		bool negative = (dividend < 0) ^ (divisor < 0) ? true : false;
		long dividend_l = labs(dividend), divisor_l = labs(divisor), result = 0;
		while (dividend_l >= divisor_l) {
			long temp = divisor_l, times = 1;
			while ((temp << 1) <= dividend_l) {
				temp <<= 1;
				times <<= 1;
			}
			result += times;
			dividend_l -= temp;
		}
		return negative ? -result : result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int ans = s.divide(125, -3);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 172. Factorial Trailing Zeroes


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		long long base = 5, count = 0;
		while (base <= n) {
			count += n / base;
			base *= 5;
		}
		return count;
	}
};

// 1137. N-th Tribonacci Number


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int tribonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int a = 0, b = 1, c = 1, tmp = 0;
		for (int i = 3; i <= n; ++i) {
			tmp = a;
			a = b;
			b = c;
			c = tmp + a + b;
		}
		return c;
	}
};

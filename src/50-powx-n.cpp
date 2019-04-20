// 50. Pow(x, n)


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		if (n == INT_MIN) {
			return myPow(x * x, n / 2);
		}
		if (n < 0) {
			n = -n;  // if n == INT_MIN, integer overflow here
			x = 1 / x;
		}
		if (n % 2 == 0)
			return myPow(x * x, n / 2);
		else
			return myPow(x * x, n / 2) * x;
	}
};

class Solution2 {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1.0;
		if (n == 1)
			return x;
		if (n < 0) {
			n = -n;
			x = 1 / x;
		}
		if (n % 2 == 0)
			return myPow(x * x, n / 2);
		else
			return myPow(x * x, n / 2) * x;
	}
};
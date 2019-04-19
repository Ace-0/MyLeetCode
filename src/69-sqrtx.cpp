// 69. Sqrt(x)


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x, mid;
		if (x == 0 || x == 1)
			return x;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (x / mid >= mid)
				left = mid + 1;
			else
				right = mid;
		}
		return left - 1;
	}
};
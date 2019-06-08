// 852. Peak Index in a Mountain Array


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int left = 0, right = A.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (A[mid + 1] > A[mid]) {
				left = mid;
			}
			else if (A[mid - 1] > A[mid]) {
				right = mid;
			}
			else {
				return mid;
			}
		}
		return -1;
	}
};

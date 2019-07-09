// 153. Find Minimum in Rotated Sorted Array


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, mid = -1;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (nums[mid] < nums[right])
				right = mid;
			else
				left = mid + 1;
		}
		return nums[left];
	}
};

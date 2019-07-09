// 154. Find Minimum in Rotated Sorted Array II


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
			else if (nums[mid] < nums[right])
				left = mid + 1;
			else {
				int i = mid;
				while (i < right && nums[i] == nums[right])
					++i;
				if (i == right)
					right = mid;
				else
					left = mid + 1;
			}
		}
		return nums[left];
	}
};

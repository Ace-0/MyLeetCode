// 162. Find Peak Element


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		// invariant: nums[left-1] < nums[left] && nums[right] > nums[right+1]
		int left = 0, right = nums.size() - 1;
		while (right - left > 1) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid + 1]) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		if (left < right)
			return nums[left] < nums[right] ? right : left;
		else
			return left;
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 1,3,2,1 };
//	
//	int ans = s.findPeakElement(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
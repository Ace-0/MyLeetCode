// 81. Search in Rotated Sorted Array II


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty())
			return false;
		int left = 0, right = nums.size() - 1, mid = -1;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (nums[mid] > nums[right]) {
				if (nums[left] <= target && target <= nums[mid])
					right = mid;
				else
					left = mid + 1;
			}
			else if (nums[mid] < nums[right]) {
				if (nums[mid] < target && target <= nums[right])
					left = mid + 1;
				else
					right = mid;
			}
			else {
				--right;
			}
		}
		return nums[left] == target;
	}
};

////  3 3 3 3 3 1 3
////  1 2 3 3 3 3
////  1 3 1 1 1 1
////  2 2 2 2 3 2
////  2 2 2 2 3 1
//
//int main() {
//	Solution s = Solution();
//
//	//vector<int> testcase = { 2,5,6,0,0,1,2 };
//	//int k = 3;
//	vector<int> testcase = { 1, 3, 1, 1, 1 };
//	int k = 3;
//	
//	bool ans = s.search(testcase, k);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
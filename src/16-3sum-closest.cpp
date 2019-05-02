// 16. 3Sum Closest


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int min_diff = INT_MAX, closest_sum = 0, cur_sum = 0;
		for (int i = 0; i < nums.size() - 2; ) {
			int left = i + 1, right = nums.size() - 1;
			while (left < right) {
				cur_sum = nums[i] + nums[left] + nums[right];
				if (cur_sum < target) {
					if (target - cur_sum < min_diff) {
						closest_sum = cur_sum;
						min_diff = target - closest_sum;
					}
					++left;
				}
				else if (cur_sum > target) {
					if (cur_sum - target < min_diff) {
						closest_sum = cur_sum;
						min_diff = closest_sum - target;
					}
					--right;
				}
				else {
					return target;
				}
			}
			while (i + 1 < nums.size() - 2 && nums[i + 1] == nums[i])
				++i;
			++i;
		}
		return closest_sum;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> nums = { -1, 2, 1, -4 };
//	int testcase = 1;
//	
//	int ans = s.threeSumClosest(nums, testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
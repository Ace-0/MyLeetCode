// 18. 4Sum


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		if (nums.size() < 4)
			return result;

		for (int i = 0; i < nums.size() - 3; ++i) {
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
				for (int j = i + 1; j < nums.size() - 2; ++j) {
					if (j == i + 1 || (j > i + 1 && nums[j] != nums[j - 1])) {
						int target_sum = target - nums[i] - nums[j];
						int left = j + 1, right = nums.size() - 1;
						while (left < right) {
							if (nums[left] + nums[right] < target_sum) {
								++left;
							}
							else if (nums[left] + nums[right] > target_sum) {
								--right;
							}
							else {
								vector<int> quadruplets = { nums[i], nums[j], nums[left], nums[right] };
								result.push_back(quadruplets);
								while (left < right && nums[left] == nums[left + 1])
									++left;
								while (left < right && nums[right] == nums[right - 1])
									--right;
								++left;
								--right;
							}
						}
					}
				}
			}
		}
		return result;
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { -3,-1,0,2,4,5 };
//	int target = 0;
//	
//	vector<vector<int>> ans = s.fourSum(testcase, target);
//
//	for (vector<int> quad : ans) {
//		for (int n : quad) {
//			cout << n << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
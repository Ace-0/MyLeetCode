class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		//

		for (int i = 0; i + 2 < nums.size(); ++i) {
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
				int target_sum = 0 - nums[i];
				int left = i + 1, right = nums.size() - 1;
				while (left < right) {
					if (nums[left] + nums[right] < target_sum) {
						++left;
					}
					else if (nums[left] + nums[right] > target_sum) {
						--right;
					}
					else {
						vector<int> triplet = { nums[i], nums[left], nums[right] };
						result.push_back(triplet);
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
		return result;
	}
};


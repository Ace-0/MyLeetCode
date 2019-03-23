class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int min_idx = 0, max_idx = 0, left = nums.size() - 1, right = 0;
		int max = nums[max_idx];
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > max) {
				max = nums[i];
				max_idx = i;
			}
			if (nums[i] < max) {
				int j = i;
				while (j > 0 && nums[i] < nums[j - 1])
					--j;
				left = j < left ? j : left;
				right = i;
			}
		}
		if ((right - left + 1) > 1)
			return (right - left + 1);
		else
			return 0;
	}
};

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2)
			return;
		int swap_index = nums.size() - 2;
		while (swap_index >= 0 && nums[swap_index] >= nums[swap_index + 1])
			--swap_index;
		if (swap_index < 0) {
			// reverse the whole array
			reverse(nums.begin(), nums.end());
			return;
		}
		// swap two number
		int alter = INT_MAX;
		int alter_index = swap_index + 1;
		int i = swap_index + 1;
		while (i < nums.size()) {
			if (nums[i] > nums[swap_index] && nums[i] <= alter) {
				alter = nums[i];
				alter_index = i;
			}
			++i;
		}
		swap(nums[swap_index], nums[alter_index]);
		// reverse [swap_index+1, nums.size()-1]
		reverse(nums.begin() + swap_index + 1, nums.end());
	}
};

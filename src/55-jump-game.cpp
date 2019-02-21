class Solution {
public:
	bool canJump(vector<int>& nums) {
		int last = nums.size() - 1;
		int current = 0, reach = 0;
		while (current <= last && current <= reach) {
			reach = max(reach, current + nums[current]);
			current++;
		}
		return reach >= last;
	}
};
// 45. Jump Game II


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int cur_pos = 0, far_pos = nums[0], step = 0;
		while (far_pos < nums.size() - 1) {
			int next_pos = cur_pos, next_far_pos = far_pos;
			for (int i = cur_pos + 1; i <= far_pos && i < nums.size(); ++i) {
				if (nums[i] + i > next_far_pos) {
					next_pos = i;
					next_far_pos = nums[i] + i;
				}
			}
			++step;
			cur_pos = next_pos;
			far_pos = next_far_pos;
		}
		return cur_pos == nums.size() - 1 ? 0 : step + 1;
	}
};

int main() {
	Solution s = Solution();

	vector<int> testcase = { 0 };
	
	int ans = s.jump(testcase);

	cout << ans << endl;

	system("pause");
	return 0;
}
// 457. Circular Array Loop


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool circularArrayLoop(vector<int>& nums) {
		int length = nums.size();
		for (int i = 0; i < length && nums[i] != 0; ++i) {
			int slow = i, fast = next_position(i, nums, length);
			while (nums[i] * nums[fast] > 0 &&
				nums[i] * nums[next_position(fast, nums, length)] > 0) {

				if (slow == fast) {
					if (slow == next_position(slow, nums, length))
						break;
					return true;
				}
				slow = next_position(slow, nums, length);
				fast = next_position(next_position(fast, nums, length), nums, length);
			}
			slow = i;
			int direction = nums[i];
			while (direction * nums[slow] > 0) {
				int next_slow = next_position(slow, nums, length);
				nums[slow] = 0;
				slow = next_slow;
			}
		}
		return false;
	}

private:
	int next_position(int cur_pos, vector<int>& nums, int length) {
		cur_pos += nums[cur_pos];
		while (cur_pos < 0)
			cur_pos += length;
		if (cur_pos >= length)
			cur_pos %= length;
		return cur_pos;
		//return (cur_pos + nums[cur_pos] + length) % length;
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<int> testcase = { 2,-1,1,2,2 };
//	vector<int> testcase = { -8,-1,1,7,2 };
//
//	bool ans = s.circularArrayLoop(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
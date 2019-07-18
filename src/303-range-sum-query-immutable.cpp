// 303. Range Sum Query - Immutable


#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	NumArray(vector<int>& nums) {
		if (!nums.empty()) {
			accu_sum = vector<int>(nums.size() + 1, 0);
			for (int i = 1; i < accu_sum.size(); ++i)
				accu_sum[i] = nums[i - 1] + accu_sum[i - 1];
		}
	}

	int sumRange(int i, int j) {
		return accu_sum[j + 1] - accu_sum[i];
	}
private:
	vector<int> accu_sum;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* int param_1 = obj->sumRange(i,j);
*/

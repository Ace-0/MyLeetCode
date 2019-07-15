// 307. Range Sum Query - Mutable


#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	NumArray(vector<int>& nums) {
		m_nums = nums;
		accu_sum = vector<int>(nums.size() + 1, 0);
		for (int i = 1; i < nums.size() + 1; ++i)
			accu_sum[i] = accu_sum[i - 1] + nums[i - 1];
	}

	void update(int i, int val) {
		int diff = val - m_nums[i];
		m_nums[i] = val;
		for (int j = i + 1; j < accu_sum.size(); ++j)
			accu_sum[j] += diff;
	}

	int sumRange(int i, int j) {
		return accu_sum[j + 1] - accu_sum[i];
	}
private:
	vector<int> accu_sum, m_nums;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/

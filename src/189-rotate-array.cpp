// 189. Rotate Array


#include <iostream>
#include <vector>

using namespace std;

// 20ms 9.5MB
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.size() - 1);
	}
private:
	void reverse(vector<int>& nums, int left, int right) {
		int tmp = 0;
		while (left < right) {
			tmp = nums[left];
			nums[left] = nums[right];
			nums[right] = tmp;
			++left;
			--right;
		}
	}
};

//// 28ms 9.7MB
//class Solution {
//public:
//	void rotate(vector<int>& nums, int k) {
//		k %= nums.size();
//		vector<int> tmp_vec;
//		for (int i = nums.size() - k; i < nums.size(); ++i)
//			tmp_vec.push_back(nums[i]);
//		for (int i = nums.size() - 1; i >= k; --i)
//			nums[i] = nums[i - k];
//		for (int i = 0; i < k; ++i)
//			nums[i] = tmp_vec[i];
//	}
//};

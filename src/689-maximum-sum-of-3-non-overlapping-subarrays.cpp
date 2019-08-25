// 689. Maximum Sum of 3 Non-Overlapping Subarrays


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int nums_size = nums.size(), sum_size = nums.size() - k + 1;
		vector<int> sum_vec(sum_size);
		int cur_sum = 0;
		for (int i = 0; i < k; ++i)
			cur_sum += nums[i];
		sum_vec[0] = cur_sum;
		for (int i = k, j = 1; i < nums_size; ++i, ++j) {
			cur_sum -= nums[i - k];
			cur_sum += nums[i];
			sum_vec[j] = cur_sum;
		}
		vector<int> max_left_idx(sum_size), max_right_idx(sum_size);
		max_left_idx[0] = 0, max_right_idx[sum_size - 1] = sum_size - 1;
		for (int i = 1, j = sum_size - 2; i < sum_size; ++i, --j) {
			if (sum_vec[i] > sum_vec[max_left_idx[i - 1]])
				max_left_idx[i] = i;
			else
				max_left_idx[i] = max_left_idx[i - 1];
			if (sum_vec[j] >= sum_vec[max_right_idx[j + 1]])
				max_right_idx[j] = j;
			else
				max_right_idx[j] = max_right_idx[j + 1];
		}
		vector<int> result(3);
		int max_arr_sum = 0;
		for (int i = k; i < sum_size - k; ++i) {
			if (sum_vec[max_left_idx[i - k]] + sum_vec[i] + sum_vec[max_right_idx[i + k]] > max_arr_sum) {
				max_arr_sum = sum_vec[max_left_idx[i - k]] + sum_vec[i] + sum_vec[max_right_idx[i + k]];
				result[0] = max_left_idx[i - k];
				result[1] = i;
				result[2] = max_right_idx[i + k];
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 1,2,1,2,6,7,5,1 };
//	int k = 2;
//	
//	vector<int> ans = s.maxSumOfThreeSubarrays(testcase, k);
//
//	for (int n : ans)
//		cout << n << " ";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
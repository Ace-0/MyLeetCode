// 209. Minimum Size Subarray Sum


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int start = 0, end = 0, cur_sum = 0, min_len = nums.size() + 1;
		while (end < nums.size()) {
			cur_sum += nums[end];
			if (cur_sum >= s) {
				while (start < end && cur_sum - nums[start] >= s) {
					cur_sum -= nums[start];
					++start;
				}
				min_len = end - start + 1 < min_len ? end - start + 1 : min_len;
			}
			++end;
		}
		return min_len == nums.size() + 1 ? 0 : min_len;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int sum = 7;
//	vector<int> testcase = { 2,3,1,2,4,3 };
//	
//	int ans = s.minSubArrayLen(sum, testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
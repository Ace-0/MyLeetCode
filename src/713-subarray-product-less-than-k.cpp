// 713. Subarray Product Less Than K


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int start = 0, end = 0, count = 0, product = 1;
		for (end = 0; end < nums.size(); ++end) {
			product *= nums[end];
			while (start < end && product >= k) {
				product /= nums[start];
				start += 1;
			}

			if (product < k)
				count += end - start + 1;
		}

		return count;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 10, 5, 2, 6 };
//	int k = 100;
//	
//	int ans = s.numSubarrayProductLessThanK(testcase, k);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 368. Largest Divisible Subset


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<int> lens(n, 1), pre(n, -1);
		int largest_len = 0, largest_len_idx = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (nums[i] % nums[j] == 0 && lens[j] + 1 > lens[i]) {
					lens[i] = lens[j] + 1;
					pre[i] = j;
				}
			}
			if (lens[i] > largest_len) {
				largest_len = lens[i];
				largest_len_idx = i;
			}
		}
		vector<int> result;
		while (largest_len_idx != -1) {
			result.push_back(nums[largest_len_idx]);
			largest_len_idx = pre[largest_len_idx];
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 1,2,4,8 };
//	
//	vector<int> ans = s.largestDivisibleSubset(testcase);
//
//	for (int n : ans)
//		cout << n << " ";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
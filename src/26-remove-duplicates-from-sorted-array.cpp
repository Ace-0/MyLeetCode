// 26. Remove Duplicates from Sorted Array


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int cur_idx = 1, replace_idx = 1;
		int pre = nums[0];
		while (cur_idx < nums.size()) {
			if (nums[cur_idx] != pre) {
				nums[replace_idx++] = nums[cur_idx];
				pre = nums[cur_idx];
			}
			++cur_idx;
		}
		nums.resize(replace_idx);
		return nums.size();
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 0,0,1,1,1,2,2,3,3,4 };
//	
//	int ans = s.removeDuplicates(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
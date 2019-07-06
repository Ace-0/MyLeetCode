// 90. Subsets II


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> path;
		sort(nums.begin(), nums.end());
		dfs(0, path, nums, result);
		return result;
	}

private:
	void dfs(int start, vector<int>& path, vector<int>& nums, vector<vector<int>>& result) {
		result.push_back(path);
		if (start == nums.size())
			return;
		for (int i = start; i < nums.size(); ++i) {
			if (i == start || nums[i] != nums[i - 1]) {
				path.push_back(nums[i]);
				dfs(i + 1, path, nums, result);
				path.pop_back();
			}
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 4, 4, 4, 1, 4 };
//	
//	vector<vector<int>> ans = s.subsetsWithDup(testcase);
//
//	for (vector<int> subset : ans) {
//		cout << "[ ";
//		for (int n : subset)
//			cout << n << " ";
//		cout << "]" << endl;
//	}
//
//	system("pause");
//	return 0;
//}
// 47. Permutations II


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		unordered_map<int, int> remain;
		for (int n : nums) {
			if (remain.find(n) == remain.end())
				remain[n] = 0;
			++remain[n];
		}
		vector<int> path;
		vector<vector<int>> result;
		const int target_len = nums.size();
		dfs(path, remain, result, target_len);
		return result;
	}

private:
	void dfs(vector<int>& path, unordered_map<int, int>& remain, vector<vector<int>>& result, const int target_len) {
		if (path.size() == target_len) {
			result.push_back(path);
			return;
		}
		for (auto it = remain.begin(); it != remain.end(); ++it) {
			if (it->second > 0) {
				path.push_back(it->first);
				--(it->second);
				dfs(path, remain, result, target_len);
				path.pop_back();
				++(it->second);
			}
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 1, 1, 2};
//	
//	vector<vector<int>> ans = s.permuteUnique(testcase);
//
//	for (vector<int> per : ans) {
//		cout << "[";
//		for (int n : per)
//			cout << n << ' ';
//		cout << "]\n";
//	}
//
//	system("pause");
//	return 0;
//}
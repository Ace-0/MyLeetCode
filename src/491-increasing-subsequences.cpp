class Solution {
public:
void dfs(vector<vector<int>> &result, vector<int> &nums, int startIndex, vector<int> &curVec) {
	if (curVec.size() >= 2) {
		result.push_back(curVec);
	}
	bool exist[201] = { false };
	for (int index = startIndex; index < nums.size(); index++) {
		if ((curVec.empty() || nums[index] >= curVec.back()) && exist[nums[index] + 100] == false) {
			exist[nums[index] + 100] = true;
			curVec.push_back(nums[index]);
			dfs(result, nums, index + 1, curVec);
			curVec.pop_back();
		}
	}
}

vector<vector<int>> findSubsequences(vector<int>& nums) {

	vector<vector<int>> result;
	vector<int> curVec;
	dfs(result, nums, 0, curVec);

	return result;
}
};
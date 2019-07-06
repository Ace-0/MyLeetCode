// 77. Combinations


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> path;
		dfs(1, n, k, path, result);
		return result;
	}
private:
	void dfs(int start, int end, int k, vector<int>& path, vector<vector<int>>& result) {
		if (path.size() == k) {
			result.push_back(path);
			return;
		}
		for (int i = start; i <= end; ++i) {
			path.push_back(i);
			dfs(i + 1, end, k, path, result);
			path.pop_back();
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	int n = 4;
//	int k = 3;
//	
//	vector<vector<int>> ans = s.combine(n, k);
//
//	for (vector<int> combo : ans) {
//		cout << "[" << combo[0];
//		for (int i = 1; i < combo.size(); ++i)
//			cout << "," << combo[i];
//		cout << "]" << endl;
//	}
//	system("pause");
//	return 0;
//}
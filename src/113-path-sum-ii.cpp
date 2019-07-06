// 113. Path Sum II


#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> results;
		if (root == nullptr)
			return results;
		vector<int> path;
		dfs(root, sum, path, results);
		return results;
	}
private:
	void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& results) {
		path.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr && root->val == sum)
			results.push_back(path);
		if (root->left)
			dfs(root->left, sum - root->val, path, results);
		if (root->right)
			dfs(root->right, sum - root->val, path, results);
		path.pop_back();
	}
};
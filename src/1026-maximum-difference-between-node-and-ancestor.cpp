// 1026. Maximum Difference Between Node and Ancestor


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>


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
	int maxAncestorDiff(TreeNode* root) {
		int min_val, max_val;
		dfs(root, min_val, max_val);
		return max_diff;
	}

private:
	int max_diff = INT_MIN;

	void dfs(TreeNode* root, int& min_val, int& max_val) {
		vector<int> min_max = { INT_MAX, INT_MIN };
		if (root == nullptr)
			return;
		int left_min = INT_MAX, left_max = INT_MIN;
		if (root->left) {
			dfs(root->left, left_min, left_max);
			max_diff = max(max_diff, abs(left_min - root->val));
			max_diff = max(max_diff, abs(left_max - root->val));
		}
		int right_min = INT_MAX, right_max = INT_MIN;
		if (root->right) {
			dfs(root->right, right_min, right_max);
			max_diff = max(max_diff, abs(right_min - root->val));
			max_diff = max(max_diff, abs(right_max - root->val));
		}
		min_val = min(root->val, min(left_min, right_min));
		max_val = max(root->val, max(left_max, right_max));
		return;
	}
};

//int main() {
//	Solution s = Solution();
//
//	TreeNode* a = new TreeNode(8);
//	TreeNode* b = new TreeNode(3);
//	TreeNode* c = new TreeNode(1);
//	TreeNode* d = new TreeNode(6);
//	TreeNode* e = new TreeNode(4);
//	TreeNode* f = new TreeNode(7);
//	TreeNode* g = new TreeNode(10);
//	TreeNode* h = new TreeNode(14);
//	TreeNode* i = new TreeNode(13);
//	a->left = b; b->left = c; b->right = d; d->left = e; d->right = f;
//	a->right = g; g->right = h; h->left = i;
//
//	int ans = s.maxAncestorDiff(a);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}

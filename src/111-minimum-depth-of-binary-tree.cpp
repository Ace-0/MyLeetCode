// 111. Minimum Depth of Binary Tree


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
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int left_depth = minDepth(root->left);
		int right_depth = minDepth(root->right);
		if (left_depth == 0 && right_depth == 0)
			return 1;
		else if (left_depth == 0)
			return right_depth + 1;
		else if (right_depth == 0)
			return left_depth + 1;
		else
			return left_depth < right_depth ? left_depth + 1 : right_depth + 1;
	}
};

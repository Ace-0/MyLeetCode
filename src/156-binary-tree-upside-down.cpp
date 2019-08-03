// 156. Binary Tree Upside Down


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		TreeNode* next = root, *prev = nullptr;
		while (root) {
			next = root->left;
			root->left = prev->right;
			root->right = prev;
			prev = root;
			root = next;
		}
		return prev;
	}
};

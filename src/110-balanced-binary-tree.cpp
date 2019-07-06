// 110. Balanced Binary Tree


#include <iostream>
#include <vector>
#include <cstdlib>

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
	bool isBalanced(TreeNode* root) {
		bool is_balanced = true;
		get_depth(root, is_balanced);
		return is_balanced;
	}
private:
	int get_depth(TreeNode* root, bool& is_balanced) {
		bool left_is_balanced = true, right_is_balanced = true;
		if (root == nullptr) {
			is_balanced = true;
			return 0;
		}
		int left_depth = get_depth(root->left, left_is_balanced);
		int right_depth = get_depth(root->right, right_is_balanced);
		if (abs(left_depth - right_depth) <= 1)
			is_balanced = true;
		else
			is_balanced = false;
		is_balanced = is_balanced & left_is_balanced & right_is_balanced;
		return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
	}
};

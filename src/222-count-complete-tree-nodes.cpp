// 222. Count Complete Tree Nodes


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
	int countNodes(TreeNode* root) {
		TreeNode *left_node = root, *right_node = root;
		int complete_level = 0;
		while (left_node && right_node) {
			left_node = left_node->left;
			right_node = right_node->right;
			++complete_level;
		}
		if (left_node->left == nullptr)
			return pow(2, complete_level + 1) - 1;
		else
			return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

// 106. Construct Binary Tree from Inorder and Postorder Traversal


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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		TreeNode* root = build_subtree(inorder, postorder, 0, 0, inorder.size());
		return root;
	}
private:
	TreeNode* build_subtree(vector<int>& inorder, vector<int>& postorder,
							int in_start, int post_start, int nodes_cnt
	) {
		if (nodes_cnt == 0)
			return nullptr;
		if (nodes_cnt == 1)
			return new TreeNode(inorder[in_start]);
		int root_num = postorder[post_start + nodes_cnt - 1];
		int left_nodes_cnt = 0;
		while (inorder[in_start + left_nodes_cnt] != root_num)
			++left_nodes_cnt;
		TreeNode* left_subtree = build_subtree(inorder, postorder, in_start, post_start, left_nodes_cnt);
		TreeNode* right_subtree = build_subtree(inorder, postorder, in_start + left_nodes_cnt + 1, post_start + left_nodes_cnt, nodes_cnt - left_nodes_cnt - 1);
		TreeNode* root = new TreeNode(root_num);
		root->left = left_subtree;
		root->right = right_subtree;
		return root;
	}
};

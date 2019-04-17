// 94. Binary Tree Inorder Traversal


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// iterative
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> vec;
		stack<TreeNode*> stk;
		stk.push(root);
		while (root || !stk.empty()) {
			if (root) {
				stk.push(root);
				root = root->left;
			}
			else {
				root = stk.top();
				stk.pop();
				vec.push_back(root->val);
				root = root->right;
			}
		}
		return vec;
	}
};

//// recursive
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int> vec;
//		traverse(root, vec);
//		return vec;
//	}
//
//private:
//	void traverse(TreeNode* root, vector<int>& vec) {
//		if (root) {
//			if (root->left)
//				traverse(root->left, vec);
//			vec.push_back(root->val);
//			if (root->right)
//				traverse(root->right, vec);
//		}
//	}
//};

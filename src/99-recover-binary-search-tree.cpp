// 99. Recover Binary Search Tree


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n) space
class Solution {
public:
	void recoverTree(TreeNode* root) {
		TreeNode *first = nullptr, *second = nullptr, *pre = new TreeNode(INT_MIN);
		dfs(root, first, second, pre);
		int temp = first->val;
		first->val = second->val;
		second->val = temp;
		return;
	}

private:
	void dfs(TreeNode* &root, TreeNode* &first, TreeNode* &second, TreeNode* &pre) {
		if (root) {
			dfs(root->left, first, second, pre);
			if (root->val < pre->val && !first)
				first = pre;
			if (root->val < pre->val && first)
				second = root;
			pre = root;
			dfs(root->right, first, second, pre);
		}
	}
};

/*
     4
    / \
   3   5
  /   /
 6   2

*/
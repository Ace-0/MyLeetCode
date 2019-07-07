// 1110. Delete Nodes And Return Forest


#include <iostream>
#include <vector>
#include <unordered_set>

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
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		vector<TreeNode*> forest;
		unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
		root = delete_nodes(root, to_delete_set, forest);
		if (root)
			forest.push_back(root);
		return forest;
	}
private:
	TreeNode* delete_nodes(TreeNode* root, unordered_set<int>& to_delete_set, vector<TreeNode*>& forest) {
		if (root == nullptr)
			return nullptr;
		root->left = delete_nodes(root->left, to_delete_set, forest);
		root->right = delete_nodes(root->right, to_delete_set, forest);
		if (to_delete_set.find(root->val) != to_delete_set.end()) {
			if (root->left)
				forest.push_back(root->left);
			if (root->right)
				forest.push_back(root->right);
			return nullptr;
		}
		else {
			return root;
		}

	}
};

//int main() {
//	Solution s = Solution();
//
//	TreeNode* a = new TreeNode(1);
//	TreeNode* b = new TreeNode(2);
//	TreeNode* c = new TreeNode(3);
//	TreeNode* d = new TreeNode(4);
//	TreeNode* e = new TreeNode(5);
//	TreeNode* f = new TreeNode(6);
//	TreeNode* g = new TreeNode(7);
//	a->left = b; a->right = c;
//	b->left = d; b->right = e; c->left = f; c->right = g;
//	vector<int> to_delete = { 3, 5 };
//
//	vector<TreeNode*> ans = s.delNodes(a, to_delete);
//
//	system("pause");
//	return 0;
//}

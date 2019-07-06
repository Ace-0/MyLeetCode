// 95. Unique Binary Search Trees II


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
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return vector<TreeNode*>();
		vector<TreeNode*> trees = build_tree(1, n);
		return trees;
	}
private:
	vector<TreeNode*> build_tree(int small, int large) {
		vector<TreeNode*> trees;
		if (small == large) {
			TreeNode* root = new TreeNode(small);
			trees.push_back(root);
			return trees;
		}
		if (small > large) {
			TreeNode* root = nullptr;
			trees.push_back(root);
			return trees;
		}
		for (int root_num = small; root_num <= large; ++root_num) {
			vector<TreeNode*> left_subtrees = build_tree(small, root_num - 1);
			vector<TreeNode*> right_subtrees = build_tree(root_num + 1, large);
			for (int i = 0; i < left_subtrees.size(); ++i) {
				for (int j = 0; j < right_subtrees.size(); ++j) {
					TreeNode* root = new TreeNode(root_num);
					root->left = left_subtrees[i];
					root->right = right_subtrees[j];
					trees.push_back(root);
				}
			}
		}
		return trees;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int k = 0;
//	
//	vector<TreeNode*> ans = s.generateTrees(k);
//
//	system("pause");
//	return 0;
//}
// 107. Binary Tree Level Order Traversal II


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr)
			return result;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int level_size = que.size();
			vector<int> level_vec;
			while (level_size > 0) {
				TreeNode* front_node = que.front();
				que.pop();
				level_vec.push_back(front_node->val);
				if (front_node->left)
					que.push(front_node->left);
				if (front_node->right)
					que.push(front_node->right);
				--level_size;
			}
			result.push_back(level_vec);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

// 103. Binary Tree Zigzag Level Order Traversal

#include <vector>
#include <iostream>
#include <queue>

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr)
			return result;
		queue<TreeNode*> que;
		que.push(root);
		bool left2right = true;
		while (!que.empty()) {
			int level_size = que.size();
			vector<int> level_vec(level_size);
			for (int i = 0; i < level_size; ++i) {
				TreeNode* front_node = que.front();
				que.pop();
				int position = left2right ? i : level_size - i - 1;
				level_vec[position] = front_node->val;

				if (front_node->left)
					que.push(front_node->left);
				if (front_node->right)
					que.push(front_node->right);
			}
			result.push_back(level_vec);
			left2right = !left2right;
		}
		return result;
	}
};

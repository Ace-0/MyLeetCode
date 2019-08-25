// 314. Binary Tree Vertical Order Traversal


#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
		if (!root)
			return vector<vector<int>>();
        map<int, vector<int>> nodes_map;
		queue<pair<TreeNode*, int>> que;
		que.push(pair<TreeNode*, int>(root, 0));
		while (!que.empty()) {
			root = que.front().first;
			int pos = que.front().second;
			que.pop();
			if (nodes_map.find(pos) == nodes_map.end())
				nodes_map[pos] = vector<int>();
			nodes_map[pos].push_back(root->val);
			if (root->left)
				que.push(pair<TreeNode*, int>(root->left, pos - 1));
			if (root->right)
				que.push(pair<TreeNode*, int>(root->right, pos + 1));
		}

		vector<vector<int>> result;
		for (auto it = nodes_map.begin(); it != nodes_map.end(); ++it) {
			result.push_back(it->second);
		}
		return result;
    }
};

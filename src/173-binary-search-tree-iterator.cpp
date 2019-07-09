// 173. Binary Search Tree Iterator


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

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		cur_node = root;
	}

	/** @return the next smallest number */
	int next() {
		while (this->hasNext()) {
			if (cur_node) {
				stk.push(cur_node);
				cur_node = cur_node->left;
			}
			else {
				cur_node = stk.top();
				stk.pop();
				int rtr_val = cur_node->val;
				cur_node = cur_node->right;
				return rtr_val;
			}
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return this->cur_node || !this->stk.empty();
	}

private:
	TreeNode* cur_node;
	stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
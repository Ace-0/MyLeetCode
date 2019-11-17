// 5264. Find Elements in a Contaminated Binary Tree


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

class FindElements {
public:
    FindElements(TreeNode* root) {
		if (root)
			recoverLeaves(root);
    }
    
    bool find(int target) {
		return exist.find(target) != exist.end();
    }

private:
	void recoverLeaves(TreeNode* root) {
		exist.insert(root->val);
		if (root->left) {
			root->left->val = root->val * 2 + 1;
			recoverLeaves(root->left);
		}
		if (root->right) {
			root->right->val = root->val * 2 + 2;
			recoverLeaves(root->right);
		}
	}

	unordered_set<int> exist;
};

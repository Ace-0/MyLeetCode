// Definition for a binary tree node.
 struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		this->max_sum = INT_MIN;
		this->maxSumFromRoot(root);
		return this->max_sum;
	}
private:
	int max_sum;

	int maxSumFromRoot(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int left_max_sum = max(this->maxSumFromRoot(root->left), 0);
		int right_max_sum = max(this->maxSumFromRoot(root->right), 0);
		this->max_sum = max(this->max_sum, root->val + left_max_sum + right_max_sum);
		return max(left_max_sum, right_max_sum) + root->val;
	}
};

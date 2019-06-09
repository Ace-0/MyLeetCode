// 5084. Insufficient Nodes in Root to Leaf Paths


#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sufficientSubset(TreeNode* root, int limit) {
		int root_sum = max_sum(root, 0, limit);
		if (root_sum < limit) {
			//delete root;
			root = nullptr;
		}
		return root;
	}
private:
	int max_sum(TreeNode* root, int top_sum, int limit) {
		if (root == nullptr)
			return 0;
		int left_child_sum = max_sum(root->left, top_sum + root->val, limit);
		if (left_child_sum + root->val + top_sum < limit) {
			//delete root->left;
			root->left = nullptr;
		}
		int right_child_sum = max_sum(root->right, top_sum + root->val, limit);
		if (right_child_sum + root->val + top_sum < limit) {
			//delete root->right;
			root->right = nullptr;
		}
		int max_child_sum = left_child_sum > right_child_sum ? left_child_sum : right_child_sum;
		return root->val + max_child_sum;
	}
};

//int main() {
//	Solution s = Solution();
//
//	//TreeNode *a = new TreeNode(5);
//	//TreeNode *b = new TreeNode(4);
//	//TreeNode *c = new TreeNode(8);
//	//TreeNode *d = new TreeNode(11);
//	//TreeNode *e = new TreeNode(17);
//	//TreeNode *f = new TreeNode(4);
//	//TreeNode *g = new TreeNode(7);
//	//TreeNode *h = new TreeNode(1);
//	//TreeNode *i = new TreeNode(5);
//	//TreeNode *j = new TreeNode(3);
//	//a->left = b; b->left = d; d->left = g; d->right = h;
//	//a->right = c; c->left = e; c->right = f; f->left = i; f->right = j;
//
//	TreeNode *a = new TreeNode(10);
//	TreeNode *b = new TreeNode(5);
//	TreeNode *c = new TreeNode(10);
//	a->left = b; a->right = c;
//
//	TreeNode *ans = s.sufficientSubset(a, 21);
//
//	system("pause");
//	return 0;
//}

// 108. Convert Sorted Array to Binary Search Tree

#include <vector>
#include <iostream>

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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return buildSubtree(0, nums.size() - 1, nums);
	}
private:
	TreeNode* buildSubtree(int low, int high, vector<int>& nums) {
		int length = high - low + 1;
		TreeNode *root = nullptr;
		if (length <= 0) {
			return root;
		}
		else if (length == 1) {
			root = new TreeNode(nums[low]);
		}
		else {
			int root_index = low + length / 2;
			root = new TreeNode(nums[root_index]);
			root->left = buildSubtree(low, root_index - 1, nums);
			root->right = buildSubtree(root_index + 1, high, nums);
		}
		return root;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { -10,-3,0,5,9 };
//	
//	TreeNode* ans = s.sortedArrayToBST(testcase);
//
//	system("pause");
//	return 0;
//}
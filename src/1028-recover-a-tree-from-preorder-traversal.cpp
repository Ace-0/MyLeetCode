// 1028. Recover a Tree From Preorder Traversal


#include <iostream>
#include <vector>
#include <string>


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
	TreeNode* recoverFromPreorder(string S) {
		int start = 0;
		return dfs_in_level(S, start, 0);
	}

	TreeNode* dfs_in_level(string& s, int& start, int depth) {
		int i = start;
		while (s[i] == '-') {
			++i;
		}
		if (i - start != depth)
			return nullptr;
		int num_start = i;
		while (i < s.length() && s[i] >= '0' && s[i] <= '9')
			++i;
		int num = std::stoi(s.substr(num_start, i - num_start));
		TreeNode* root = new TreeNode(num);
		start = i;
		root->left = dfs_in_level(s, start, depth + 1);
		root->right = dfs_in_level(s, start, depth + 1);
		return root;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "1-401--349---90--88";
//
//	TreeNode* ans = s.recoverFromPreorder(testcase);
//
//	system("pause");
//	return 0;
//}

// 297. Serialize and Deserialize Binary Tree


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
 
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string result = "";
		if (root) {
			result += to_string(root->val);
			serialize_helper(root->left, result);
			serialize_helper(root->right, result);
		}
		return result;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int start = 0, end = data.length() - 1;
		return deserialize_helper(data, start, end);
	}

private:
	void serialize_helper(TreeNode* root, string& str) {
		str += (",");
		if (root) {
			str += (to_string(root->val));
			serialize_helper(root->left, str);
			serialize_helper(root->right, str);
		}
		else {
			str += ("null");
		}
	}
	TreeNode* deserialize_helper(const string& str, int& start, int end) {
		string val_str = "";
		while (start <= end && str[start] != ',') {
			val_str += str[start];
			++start;
		}
		++start;
		TreeNode* root = nullptr;
		if (!val_str.empty() && val_str != "null") {
			root = new TreeNode(stoi(val_str));
			root->left = deserialize_helper(str, start, end);
			root->right = deserialize_helper(str, start, end);
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//int main() {
//	Codec codec;
//
//	TreeNode* a = new TreeNode(1);
//	TreeNode* b = new TreeNode(2);
//	TreeNode* c = new TreeNode(3);
//	TreeNode* d = new TreeNode(4);
//	a->left = b; a->right = c; c->left = d;
//
//	TreeNode* e = codec.deserialize(codec.serialize(a));
//
//	system("pause");
//	return 0;
//}
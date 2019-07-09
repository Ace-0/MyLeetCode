// 117. Populating Next Right Pointers in Each Node II


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr)
			return nullptr;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			int level_size = que.size();
			while (level_size > 0) {
				Node* front_node = que.front();
				que.pop();
				if (level_size != 1)
					front_node->next = que.front();
				if (front_node->left)
					que.push(front_node->left);
				if (front_node->right)
					que.push(front_node->right);
				--level_size;
			}
		}
		return root;
	}
};

//int main() {
//	Solution s = Solution();
//
//	Node* d = new Node(4, nullptr, nullptr, nullptr);
//	Node* e = new Node(5, nullptr, nullptr, nullptr);
//	Node* f = new Node(7, nullptr, nullptr, nullptr);
//	Node* b = new Node(2, d, e, nullptr);
//	Node* c = new Node(3, nullptr, f, nullptr);
//	Node* a = new Node(1, b, c, nullptr);
//
//	Node* ans = s.connect(a);
//
//	system("pause");
//	return 0;
//}
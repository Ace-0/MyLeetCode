// 116. Populating Next Right Pointers in Each Node


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

// 64ms 27.1MB
class Solution {
public:
	Node* connect(Node* root) {
		Node* leftmost_node = root, *cur_node = nullptr, *pre_node = nullptr;
		while (leftmost_node && leftmost_node->left) {
			cur_node = leftmost_node;
			pre_node = nullptr;
			while (cur_node) {
				if (pre_node)
					pre_node->right->next = cur_node->left;
				cur_node->left->next = cur_node->right;
				pre_node = cur_node;
				cur_node = cur_node->next;
			}
			leftmost_node = leftmost_node->left;
		}
		return root;
	}
};

//// using queue
//// 76ms 27.3MB
//class Solution {
//public:
//	Node* connect(Node* root) {
//		if (root == nullptr)
//			return root;
//		queue<Node*> que;
//		que.push(root);
//		while (!que.empty()) {
//			int cur_level_size = que.size();
//			Node* pre_node = nullptr, *cur_node = nullptr;
//			while (cur_level_size--) {
//				cur_node = que.front();
//				que.pop();
//				if (pre_node)
//					pre_node->next = cur_node;
//				pre_node = cur_node;
//				if (cur_node->left) {
//					que.push(cur_node->left);
//					que.push(cur_node->right);
//				}
//			}
//		}
//		return root;
//	}
//};

// 430. Flatten a Multilevel Doubly Linked List


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution {
public:
	Node* flatten(Node* head) {
		Node* cur_node = head, *pre_node = nullptr;
		stack<Node*> nexts;
		while (cur_node || !nexts.empty()) {
			if (!cur_node) {
				cur_node = nexts.top();
				nexts.pop();
				pre_node->next = cur_node;
				cur_node->prev = pre_node;
			}
			if (cur_node->child) {
				if (cur_node->next)
					nexts.push(cur_node->next);
				cur_node->next = cur_node->child;
				cur_node->child = nullptr;
				cur_node->next->prev = cur_node;
			}
			pre_node = cur_node;
			cur_node = cur_node->next;
		}
		return head;
	}
};

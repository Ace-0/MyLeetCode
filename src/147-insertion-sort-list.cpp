// 147. Insertion Sort List


#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !(head->next))
			return head;
		ListNode *pre_head = new ListNode(0);
		pre_head->next = head;
		ListNode *cur_node = head->next, *pre_node = nullptr, *next_node = nullptr;
		head->next = nullptr;
		while (cur_node) {
			pre_node = pre_head;
			while (pre_node->next && cur_node->val >= pre_node->next->val) {
				pre_node = pre_node->next;
			}
			next_node = cur_node->next;
			cur_node->next = pre_node->next;
			pre_node->next = cur_node;
			cur_node = next_node;
		}
		head = pre_head->next;
		delete pre_head;
		return head;
	}
};

//int main() {
//	Solution s = Solution();
//
//	ListNode *head = new ListNode(-1);
//	ListNode *a = new ListNode(5);
//	ListNode *b = new ListNode(3);
//	ListNode *c = new ListNode(4);
//	ListNode *d = new ListNode(0);
//	head->next = a;
//	a->next = b;
//	b->next = c;
//	c->next = d;
//
//	head = s.insertionSortList(head);
//
//	while (head) {
//		cout << head->val << "-->";
//		head = head->next;
//	}
//	cout << "nullptr" << endl;
//
//	system("pause");
//	return 0;
//}
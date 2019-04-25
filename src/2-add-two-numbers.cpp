// 2. Add Two Numbers


#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* head = new ListNode(-1);  // not the first
		ListNode* pre_node = head;
		while (l1 || l2) {
			int v1 = l1 ? l1->val : 0;
			int v2 = l2 ? l2->val : 0;
			pre_node->next = new ListNode((v1 + v2 + carry) % 10);
			carry = (v1 + v2 + carry) > 9 ? 1 : 0;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
			pre_node = pre_node->next;
		}
		if (carry == 1)
			pre_node->next = new ListNode(1);
		pre_node = head;
		head = head->next;
		delete pre_node;
		return head;
	}
};

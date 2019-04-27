// 86. Partition List


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
	ListNode* partition(ListNode* head, int x) {
		ListNode *front_head = new ListNode(0), *back_head = new ListNode(0);
		ListNode *front = front_head, *back = back_head, *cur = head;
		while (cur) {
			if (cur->val < x) {
				front->next = cur;
				front = front->next;
			}
			else {
				back->next = cur;
				back = back->next;
			}
			cur = cur->next;
		}
		back->next = nullptr;
		front->next = back_head->next;
		head = front_head->next;
		delete front_head, back_head;
		return head;
	}
};

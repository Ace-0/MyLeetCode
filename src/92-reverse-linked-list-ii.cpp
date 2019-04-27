// 92. Reverse Linked List II


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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *empty_head = new ListNode(0);
		empty_head->next = head;
		ListNode *pre = empty_head;
		for (int i = 0; i < m - 1; ++i) {
			pre = pre->next;
		}
		ListNode *cur = pre->next, *temp = nullptr;
		for (int i = m; i < n; ++i) {
			temp = pre->next;
			pre->next = cur->next;
			cur->next = cur->next->next;
			pre->next->next = temp;
		}
		head = empty_head->next;
		delete empty_head;
		return head;
	}
};

//class Solution {
//public:
//	ListNode* reverseBetween(ListNode* head, int m, int n) {
//		ListNode *empty_head = new ListNode(0);
//		empty_head->next = head;
//		ListNode *last_before_m = empty_head, *first_after_n = nullptr;
//		for (int i = 0; i < m - 1; ++i) {
//			last_before_m = last_before_m->next;
//		}
//		ListNode *sub_tail = last_before_m->next, *pre = last_before_m->next, *cur = pre->next, *next = nullptr;
//		for (int i = m; i < n; ++i) {
//			next = cur->next;
//			cur->next = pre;
//			pre = cur;
//			cur = next;
//		}
//		last_before_m->next = pre;
//		sub_tail->next = cur;
//		head = empty_head->next;
//		delete empty_head;
//		return head;
//	}
//};
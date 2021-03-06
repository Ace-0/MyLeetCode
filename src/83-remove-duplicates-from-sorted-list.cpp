// 83. Remove Duplicates from Sorted List


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *empty_head = new ListNode(0);
		empty_head->next = head;
		ListNode *pre = empty_head, *cur = head;
		while (cur) {
			while (cur->next && cur->val == cur->next->val) {
				cur = cur->next;
			}
			pre->next = cur;
			pre = cur;
			cur = cur->next;
		}
		head = empty_head->next;
		delete empty_head;
		return head;
	}
};

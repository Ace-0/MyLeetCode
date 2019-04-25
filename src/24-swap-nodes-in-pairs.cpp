// 24. Swap Nodes in Pairs


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
	ListNode* swapPairs(ListNode* head) {
		if (!head || !(head->next))
			return head;
		ListNode *pre = nullptr, *first = head, *second = head->next;
		head = head->next;
		while (first && second) {
			if (pre)
				pre->next = second;
			first->next = second->next;
			second->next = first;

			pre = first;
			if (first->next) {
				first = first->next;
				second = first->next;
			}
			else {
				first = nullptr;
				second = nullptr;
			}
		}
		return head;
	}
};

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
	// Reset nodes to counteract the difference
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
			return nullptr;
		ListNode *tmpA = headA, *tmpB = headB;
		while (tmpA != tmpB) {
			tmpA = tmpA ? tmpA->next : headB;
			tmpB = tmpB ? tmpB->next : headA;
		}
		return tmpA;
	}
	/*
	// Get the length difference of two list fisrt
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int m = 0;
		ListNode* tmp = headA;
		while (tmp) {
			++m;
			tmp = tmp->next;
		}
		int n = 0;
		tmp = headB;
		while (tmp) {
			++n;
			tmp = tmp->next;
		}
		int diff = m - n;
		ListNode* tmpA = headA, *tmpB = headB;
		if (diff > 0) {
			while (diff) {
				tmpA = tmpA->next;
				--diff;
			}
		}
		else {
			while (diff != 0) {
				tmpB = tmpB->next;
				++diff;
			}
		}
		while (tmpA && tmpB) {
			if (tmpA == tmpB)
				return tmpA;
			tmpA = tmpA->next;
			tmpB = tmpB->next;
		}
		return nullptr;
	}
	*/

};

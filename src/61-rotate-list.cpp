// 61. Rotate List


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
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next)
			return head;
		int length = 0;
		ListNode *cur = head;
		while (cur) {
			++length;
			cur = cur->next;
		}
		k = length - k % length;
		ListNode *pre = head;
		while (k > 1) {
			--k;
			pre = pre->next;
		}
		cur = pre->next;
		if (cur) {
			while (cur->next)
				cur = cur->next;
			cur->next = head;
			head = pre->next;
			pre->next = nullptr;
		}
		return head;
	}
};

//int main() {
//	Solution s = Solution();
//
//	ListNode *a = new ListNode(1);
//	ListNode *b = new ListNode(2);
//	ListNode *c = new ListNode(3);
//	ListNode *d = new ListNode(4);
//	ListNode *e = new ListNode(5);
//	a->next = b; b->next = c; c->next = d; d->next = e;
//
//	ListNode *ans = s.rotateRight(a, 2);
//
//	while (ans) {
//		cout << ans->val << "-->";
//		ans = ans->next;
//	}
//	cout << "nullptr" << endl;
//
//	system("pause");
//	return 0;
//}
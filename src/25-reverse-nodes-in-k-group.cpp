// 25. Reverse Nodes in k-Group


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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1)
			return head;
		int length = 0;
		ListNode* cur = head;
		while (cur) {
			++length;
			cur = cur->next;
		}
		length = length - length % k;
		ListNode* pre_head = new ListNode(0);
		ListNode* last_tail = pre_head, *cur_tail = nullptr;
		ListNode *pre = nullptr, *next = nullptr;
		cur = head;
		while (length > 0) {
			cur_tail = cur;
			pre = cur;
			cur = cur->next;
			for (int i = 0; i < k - 1; ++i) {
				next = cur->next;
				cur->next = pre;
				pre = cur;
				cur = next;
			}
			last_tail->next = pre;
			last_tail = cur_tail;
			length -= k;
		}
		last_tail->next = cur;
		head = pre_head->next;
		delete pre_head;
		return head;
	}
};

//int main() {
//	Solution s = Solution();
//
//	ListNode *a = new ListNode(1); ListNode *b = new ListNode(2); ListNode *c = new ListNode(3); ListNode *d = new ListNode(4);
//	ListNode *e = new ListNode(5); ListNode *f = new ListNode(6); ListNode *g = new ListNode(7);
//	a->next = b; b->next = c; c->next = d; d->next = e; e->next = f; f->next = g;
//
//	ListNode *ans = s.reverseKGroup(a, 3);
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
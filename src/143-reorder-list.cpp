// 143. Reorder List


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode *slow = head, *fast = head;
		stack<ListNode*> stk;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		// odd
		if (fast) {
			fast = slow;
			slow = slow->next;
			fast->next = nullptr;
		}
		while (slow) {
			stk.push(slow);
			slow = slow->next;
		}
		slow = head;
		while (!stk.empty()) {
			fast = stk.top();
			stk.pop();
			fast->next = slow->next;
			slow->next = fast;
			slow = fast->next;
		}
		if (slow)
			slow->next = nullptr;
	}
};

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return nullptr;
		ListNode *slow = head->next;
		ListNode *fast = slow->next;
		while (fast && (fast != slow)) {
			slow = slow->next;
			fast = fast->next ? fast->next->next : nullptr;
		}
		if (fast) {
			slow = head;
			while (fast != slow) {
				slow = slow->next;
				fast = fast->next;
			}
			return fast;
		}
		else
		{
			return nullptr;
		}
	}
};

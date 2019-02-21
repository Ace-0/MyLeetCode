class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p = head, *q = head;
		while (n-- >= 0) {
			if (q == NULL) {
				ListNode* temp = head;
				head = head->next;
				delete temp;
				return head;
			}
			q = q->next;
		}
		while (q != NULL) {
			q = q->next;
			p = p->next;
		}
		ListNode* temp = p->next;
		p->next = p->next->next;
		delete temp;
		return head;
	}
};
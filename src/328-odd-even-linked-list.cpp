// 328. Odd Even Linked List


#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *odd_head = head, *odd = head;
		ListNode *even_head = odd->next, *even = odd->next;
		while (odd && even) {
			odd->next = even->next;
			if (odd->next) {
				odd = odd->next;
				even->next = odd->next;
			}				
			even = even->next;
		}
		odd->next = even_head;
		return odd_head;
	}
};

//int main() {
//	Solution s = Solution();
//
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//	ListNode* node4 = new ListNode(4);
//	ListNode* node5 = new ListNode(5);
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//
//	ListNode* head = s.oddEvenList(node1);
//
//	while (head) {
//		cout << head->val << "->";
//		head = head->next;
//	}
//	cout << "nullptr" << endl;
//
//	system("pause");
//	return 0;
//}
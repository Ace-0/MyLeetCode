// 445. Add Two Numbers II


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> stack1, stack2;
		while (l1 || l2) {
			if (l1) {
				stack1.push(l1->val);
				l1 = l1->next;
			}
			if (l2) {
				stack2.push(l2->val);
				l2 = l2->next;
			}
		}
		ListNode *next_node = nullptr, *cur_node = nullptr;
		int v1 = 0, v2 = 0, cur_sum = 0, carry = 0;
		while (!stack1.empty() || !stack2.empty()) {
			if (!stack1.empty()) {
				v1 = stack1.top();
				stack1.pop();
			}
			else {
				v1 = 0;
			}
			if (!stack2.empty()) {
				v2 = stack2.top();
				stack2.pop();
			}
			else {
				v2 = 0;
			}
			cur_sum = v1 + v2 + carry;
			cur_node = new ListNode(cur_sum % 10);
			cur_node->next = next_node;
			next_node = cur_node;
			carry = cur_sum / 10;
		}
		if (carry == 1) {
			cur_node = new ListNode(1);
			cur_node->next = next_node;
		}
		return cur_node;
	}
};

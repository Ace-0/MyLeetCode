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
		if (!head || !(head->next))
			return head;

		unordered_set<int> hash_set;
		ListNode* pre = head, *cur = head->next;
		hash_set.insert(head->val);
		
		while (cur) {
			if (hash_set.find(cur->val) == hash_set.end()) {
				hash_set.insert(cur->val);
				pre = cur;
				cur = cur->next;
			}
			else {
				cur = cur->next;
				delete pre->next;
				pre->next = cur;
			}
		}
		return head;
	}
};

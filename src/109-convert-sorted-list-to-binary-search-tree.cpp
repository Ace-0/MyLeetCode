// 109. Convert Sorted List to Binary Search Tree


#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return build_subtree(head, nullptr);
	}
private:
	TreeNode* build_subtree(ListNode *head, ListNode *tail) {
		if (head == tail) {
			return nullptr;
		}
		else if (head->next == tail) {
			return new TreeNode(head->val);
		}
		else {
			ListNode *slow = head, *fast = head;
			while ((fast != tail) && (fast->next != tail)) {
				slow = slow->next;
				fast = fast->next->next;
			}
			TreeNode *root = new TreeNode(slow->val);
			root->left = build_subtree(head, slow);
			root->right = build_subtree(slow->next, tail);
			return root;
		}
	} 
};

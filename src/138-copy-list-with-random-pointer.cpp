// 138. Copy List with Random Pointer


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;
	Node() {}
	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};


class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return head;
		Node *n1, *n2;
		n1 = head;
		while (n1) {
			n2 = new Node(n1->val, n1->next, nullptr);
			n1->next = n2;
			n1 = n2->next;
		}
		Node *new_head = head->next;
		n1 = head;
		while (n1) {
			n2 = n1->next;
			if (n1->random)
				n2->random = n1->random->next;
			n1 = n2->next;
		}
		n1 = head;
		while (n1) {
			n2 = n1->next;
			n1->next = n2->next;
			n1 = n1->next;
			if (n1)
				n2->next = n1->next;
		}
		return new_head;
	}
};

// https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43497/2-clean-C%2B%2B-algorithms-without-using-extra-arrayhash-table.-Algorithms-are-explained-step-by-step.
//
// Here's how the 1st algorithm goes.
// Consider l1 as a node on the 1st list and l2 as the corresponding node on 2nd list.
// Step 1:
// Build the 2nd list by creating a new node for each node in 1st list. 
// While doing so, insert each new node after it's corresponding node in the 1st list.
// Step 2:
// The new head is the 2nd node as that was the first inserted node.
// Step 3:
// Fix the random pointers in the 2nd list: (Remember that l1->next is actually l2)
// l2->random will be the node in 2nd list that corresponds l1->random, 
// which is next node of l1->random.
// Step 4:
// Separate the combined list into 2: Splice out nodes that are part of second list. 
// Return the new head that we saved in step 2.
//

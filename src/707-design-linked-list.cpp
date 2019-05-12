// 707. Design Linked List


#include <iostream>
#include <vector>

using namespace std;

class MyLinkedList {
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		empty_head = new ListNode(0);
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0)
			return -1;
		ListNode *cur = empty_head->next;
		while (index > 0 && cur) {
			--index;
			cur = cur->next;
		}
		return cur ? cur->val : -1;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode *new_node = new ListNode(val);
		new_node->next = empty_head->next;
		empty_head->next = new_node;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode *tail = empty_head;
		while (tail->next)
			tail = tail->next;
		tail->next = new ListNode(val);
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index < 0)
			index = 0; 
		ListNode *pre = empty_head;
		while (index > 0 && pre) {
			--index;
			pre = pre->next;
		}
		if (pre) {
			ListNode *new_node = new ListNode(val);
			new_node->next = pre->next;
			pre->next = new_node;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0)
			return;
		ListNode *pre = empty_head;
		while (index > 0 && pre) {
			--index;
			pre = pre->next;
		}
		if (pre) {
			ListNode *temp = pre->next;
			if (temp) {
				pre->next = temp->next;
				delete temp;
			}
		}
	}

private:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int v) : val(v), next(nullptr) {}
	};
	ListNode* empty_head;
};

//int main() {
//	// Your MyLinkedList object will be instantiated and called as such :
//	MyLinkedList* obj = new MyLinkedList();
//	obj->addAtHead(1);
//	obj->addAtTail(3);
//	obj->addAtIndex(1, 2);
//	obj->addAtIndex(0, 0);
//	obj->addAtIndex(4, 4);
//	obj->addAtIndex(10, 10);
//	cout << obj->get(-1);
//	cout << obj->get(0);
//	cout << obj->get(3);
//	cout << obj->get(10);
//	obj->deleteAtIndex(-1);
//	obj->deleteAtIndex(2);
//	obj->deleteAtIndex(10);
//
//	system("pause");
//	return 0;
//}
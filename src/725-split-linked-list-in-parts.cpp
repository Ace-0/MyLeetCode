// 725. Split Linked List in Parts


#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		ListNode* tmp = root;
		int total_len = 0;
		while (tmp != nullptr) {
			++total_len;
			tmp = tmp->next;
		}
		int part_len = total_len / k;
		int remain_len = total_len % k;

		vector<ListNode*> result(k, nullptr);
		for (int i = 0; i < k; ++i) {
			int cur_part_len = part_len;
			if (remain_len > 0) {
				++cur_part_len;
				--remain_len;
			}

			if (cur_part_len > 0) {
				result[i] = root;
				for (int j = 1; j < cur_part_len; ++j)
					root = root->next;

				tmp = root->next;
				root->next = nullptr;
				root = tmp;
			}
		}
		return result;
	}
};

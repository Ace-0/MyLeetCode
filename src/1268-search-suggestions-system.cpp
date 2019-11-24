// 1269. Number of Ways to Stay in the Same Place After Some Steps


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
		for (string& str : products)
			insertString(str);
		
		vector<vector<string>> result;
		TrieNode* curNode = root;
		for (char ch : searchWord) {
			vector<string> curResult;
			if (curNode && curNode->children[ch - 'a']) {
				curNode = curNode->children[ch - 'a'];
				curResult = vector<string>(curNode->priQue.size(), "");
				for (int i = curResult.size() - 1; i >= 0 && !curNode->priQue.empty(); --i) {
					curResult[i] = curNode->priQue.top();
					curNode->priQue.pop();
				}
			} else {
				curNode = nullptr;
			}
			result.push_back(curResult);
		}
		return result;
    }
private:
	struct TrieNode {
		priority_queue<string> priQue;
		vector<TrieNode*> children;
		TrieNode() {
			priQue = priority_queue<string>();
			children = vector<TrieNode*>(26, nullptr);
		}
	};

	TrieNode* root;
	
	void insertString(string str) {
		TrieNode* curNode = root;
		for (char ch : str) {
			if (curNode->children[ch - 'a'] == nullptr)
				curNode->children[ch - 'a'] = new TrieNode();
			curNode = curNode->children[ch - 'a'];
			curNode->priQue.push(str);
			if (curNode->priQue.size() > 3)
				curNode->priQue.pop();
		}
	}
	
};

// int main() {
// 	Solution s = Solution();

// 	vector<string> test1 = { "mobile", "mouse", "moneypot", "monitor", "mousepad" };
// 	vector<string> test2 = { "havana" };
// 	vector<string> test3 = { "bags","baggage","banner","box","cloths" };
// 	vector<string> test4 = { "havana" };
// 	vector<string> test5 = { "mobile", "mouse", "moneypot", "monitor", "mousepad" };

// 	vector<vector<string>> ans1 = s.suggestedProducts(test1, "mouse");
// 	vector<vector<string>> ans2 = s.suggestedProducts(test2, "havana");
// 	vector<vector<string>> ans3 = s.suggestedProducts(test3, "bags");
// 	vector<vector<string>> ans4 = s.suggestedProducts(test4, "tatiana");
// 	vector<vector<string>> ans5 = s.suggestedProducts(test5, "moneypotyy");

// 	return 0;
// }
// 212. Word Search II


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;
		TrieNode* trie_root = build_trie_tree(words);
		// board[i][j] == '.' means board[i][j] has been visited
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				dfs(board, i, j, trie_root, result);
			}
		}

		return result;
	}

private:
	struct TrieNode {
		string str;
		TrieNode* next[26];
		TrieNode() : str("") {
			fill(next, next + 26, nullptr);
		}
	};

	TrieNode* build_trie_tree(vector<string>& words) {
		TrieNode* root = new TrieNode();
		for (string word : words) {
			TrieNode* cur_node = root;
			for (char ch : word) {
				if (cur_node->next[ch - 'a'] == nullptr)
					cur_node->next[ch - 'a'] = new TrieNode();
				cur_node = cur_node->next[ch - 'a'];
			}
			cur_node->str = word;
		}
		return root;
	}

	void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>& result) {
		char ch = board[i][j];
		if (ch != '.' && root->next[ch - 'a']) {
			board[i][j] = '.';
			root = root->next[ch - 'a'];
			if (root->str != "") {
				result.push_back(root->str);
				root->str = "";
			}
			if (i - 1 >= 0)
				dfs(board, i - 1, j, root, result);
			if (i + 1 < board.size())
				dfs(board, i + 1, j, root, result);
			if (j - 1 >= 0)
				dfs(board, i, j - 1, root, result);
			if (j + 1 < board[0].size())
				dfs(board, i, j + 1, root, result);
			board[i][j] = ch;
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<char>> testcase = {
//		{'o','a','a','n'},
//		{'e','t','a','e'},
//		{'i','h','k','r'},
//		{'i','f','l','v'}
//	};
//	vector<string> words = { "oath","pea","eat","rain" };
//
//	vector<string> ans = s.findWords(testcase, words);
//
//	for (string str : ans)
//		cout << str << ' ';
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
// 211. Add and Search Word - Data structure design


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* cur_node = root;
		int len = word.length(), index = 0;
		while (index < len) {
			if (cur_node->children[word[index] - 'a'] == nullptr)
				cur_node->children[word[index] - 'a'] = new TrieNode();
			cur_node = cur_node->children[word[index] - 'a'];
			++index;
		}
		cur_node->children[26] = new TrieNode();
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		int len = word.length(), index = 0;
		queue<TrieNode*> que;
		que.push(root);
		while (index < len) {
			if (que.empty())
				return false;
			int level_size = que.size();
			while (level_size > 0) {
				TrieNode* cur_node = que.front();
				que.pop();
				if (word[index] == '.') {
					for (int i = 0; i < 26; ++i)
						if (cur_node->children[i])
							que.push(cur_node->children[i]);
				}
				else {
					if (cur_node->children[word[index] - 'a'])
						que.push(cur_node->children[word[index] - 'a']);
				}
				--level_size;
			}
			++index;
		}
		while (!que.empty()) {
			if (que.front()->children[26])
				return true;
			que.pop();
		}
		return false;
	}

private:
	struct TrieNode {
		vector<TrieNode*> children;
		TrieNode() {
			children = vector<TrieNode*>(27, nullptr);  // a,b,...,y,z,$
		}
	};
	TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

 //int main() {
	//WordDictionary s = WordDictionary();
 //
	//s.addWord("at");
	//s.addWord("and");
	//s.addWord("an");
	//cout << s.search("a") << endl;    // 0
	//cout << s.search(".at") << endl;  // 0
	//s.addWord("bat");
	//cout << s.search(".at") << endl;  // 1
	//cout << s.search("an.") << endl;  // 1
	//cout << s.search("a.d.") << endl; // 0
	//cout << s.search("b.") << endl;   // 0
	//cout << s.search("a.d") << endl;  // 1
	//cout << s.search(".") << endl;    // 0

 //	system("pause");
 //	return 0;
 //}
// 642. Design Search Autocomplete System


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class AutocompleteSystem {
public:
	AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
		root = new TrieNode("", 0);
		cur_sentence = "";
		cur_match_node = root;
		for (int i = 0; i < sentences.size(); ++i)
			insert_string(sentences[i], times[i]);
	}

	vector<string> input(char c) {
		cur_sentence += c;
		if (c == '#') {
			cur_sentence.pop_back();  // remove '#'
			insert_string(cur_sentence, 1);
			cur_match_node = root;
			cur_sentence = "";
		}
		else {
			if (cur_match_node) {
				if (cur_match_node->children[get_ch_code(c)] != nullptr) {
					search_strings(cur_match_node->children[get_ch_code(c)]);
				}
				cur_match_node = cur_match_node->children[get_ch_code(c)];
			}
		}
		vector<string> result;
		while (!pri_que.empty()) {
			result.push_back(pri_que.top()->str);
			pri_que.pop();
		}
		reverse(result.begin(), result.end());
		return result;
	}

private:
	struct TrieNode {
		string str;
		int degree;
		vector<TrieNode*> children;
		TrieNode(string s, int d) : str(s), degree(d), children(vector<TrieNode*>(27, nullptr)) {}
	};
	TrieNode* root;

	class Compare {
	public:
		bool operator() (TrieNode* a, TrieNode* b) {
			return a->degree == b->degree ? a->str < b->str : a->degree > b->degree;
		}
	};
	priority_queue<TrieNode*, std::vector<TrieNode*>, Compare> pri_que;

	TrieNode* cur_match_node;

	string cur_sentence;

	int get_ch_code(char ch) {
		int ch_code = 0;
		if (ch == ' ')
			ch_code = 26;
		else
			ch_code = ch - 'a';
		return ch_code;
	}

	void insert_string(string str, int degree) {
		TrieNode* node = root;
		for (char ch : str) {
			int ch_code = get_ch_code(ch);
			if (node->children[ch_code] == nullptr)
				node->children[ch_code] = new TrieNode("", 0);
			node = node->children[ch_code];
		}
		node->str = str;
		node->degree += degree;
	}

	void search_strings(TrieNode* node) {
		if (node->str != "") {
			pri_que.push(node);
			if (pri_que.size() > 3)
				pri_que.pop();
		}
		for (int i = 0; i < node->children.size(); ++i) {
			if (node->children[i] != nullptr)
				search_strings(node->children[i]);
		}
	}
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

//void output(const vector<string>& result) {
//	cout << "| ";
//	for (const string& p : result)
//		cout << p << " | ";
//	cout << endl;
//}

//int main() {
//	
//	vector<string> sentences = { "iii", "i", "ironman", "i love leetcode" };
//	vector<int> times = { 2, 1, 1, 2 };
//	AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
//	
//	vector<string> param;
//	
//	param = obj->input('i');
//	output(param);
//
//	param = obj->input(' ');
//	output(param);
//
//	param = obj->input('l');
//	output(param);
//
//	param = obj->input('o');
//	output(param);
//
//	param = obj->input('v');
//	output(param);
//
//	param = obj->input('e');
//	output(param);
//
//	param = obj->input('#');
//	output(param);
//
//	param = obj->input('i');
//	output(param);
//
//	system("pause");
//	return 0;
//}
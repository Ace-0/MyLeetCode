// 140. Word Break II


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// memorized DFS
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_map<int, vector<string>> memory;  // memory[i] means valid strings start from index i
		vector<string> results;
		memory[s.length()] = vector<string>({ "" });
		return dfs(s, 0, memory, wordDict);
	}
private:
	vector<string> dfs(string& s, int start, unordered_map<int, vector<string>>& memory, vector<string>& wordDict) {
		if (memory.find(start) != memory.end())
			return memory[start];

		vector<string> sentences;
		for (string word : wordDict) {
			string sub_string = s.substr(start, word.length());
			if (sub_string == word) {
				vector<string> sub_sentences = dfs(s, start + word.length(), memory, wordDict);
				for (string sub_sen : sub_sentences) {
					sentences.push_back(sub_sen == "" ? word : word + " " + sub_sen);
				}
			}
		}
		memory[start] = sentences;
		return sentences;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "catsanddog";
//	vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
//
//	vector<string> ans = s.wordBreak(testcase, wordDict);
//
//	for (string str : ans)
//		cout << str << endl;
//
//	system("pause");
//	return 0;
//}
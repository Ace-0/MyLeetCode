// 269. Alien Dictionary


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	string alienOrder(vector<string>& words) {
		unordered_map<char, unordered_set<char>> directed_graph;
		unordered_map<char, int> in_degrees;

		for (int j = 0; j < words[0].size(); ++j)
			if (in_degrees.find(words[0][j]) == in_degrees.end())
				in_degrees[words[0][j]] = 0;

		for (int i = 1; i < words.size(); ++i) {
			int j = 0;
			// to find the first different char in words[i - 1] and words[i]
			while (j < words[i - 1].size() && j < words[i].size() && words[i - 1][j] == words[i][j]) {
				if (in_degrees.find(words[i][j]) == in_degrees.end())
					in_degrees[words[i][j]] = 0;
				++j;
			}
			// add an edge in graph
			if (j < words[i - 1].size() && j < words[i].size()) {
				if (directed_graph[words[i - 1][j]].find(words[i][j]) == directed_graph[words[i - 1][j]].end()) {
					directed_graph[words[i - 1][j]].insert(words[i][j]);
					++in_degrees[words[i][j]];
				}
				++j;
			}
			// record the remaining chars
			while (j < words[i].size()) {
				if (in_degrees.find(words[i][j]) == in_degrees.end())
					in_degrees[words[i][j]] = 0;
				++j;
			}
		}
		queue<char> que;
		for (auto p : in_degrees)
			if (p.second == 0)
				que.push(p.first);
		string result = "";
		while (!que.empty()) {
			char front = que.front();
			result += front;
			que.pop();
			for (char next : directed_graph[front]) {
				--in_degrees[next];
				if (in_degrees[next] == 0)
					que.push(next);
			}
		}

		if (result.length() != in_degrees.size())
			return "";
		else
			return result;		
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<string> words = { "wrt", "wrf", "er", "ett", "rftt" };
//	//vector<string> words = { "ab", "adc" };  // abcd   abdc
//	vector<string> words = { "a", "a" };
//	//vector<string> words = { "z", "x", "z" };
//
//	string ans = s.alienOrder(words);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 127. Word Ladder


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> remain(wordList.begin(), wordList.end());
		queue<string> que;
		que.push(beginWord);
		int level = 1;
		while (!que.empty()) {
			int cur_size = que.size();
			while (cur_size > 0) {
				string front = que.front();
				if (front == endWord) {
					return level;
				}
				que.pop();
				remain.erase(front);
				for (int i = 0; i < front.length(); ++i) {
					char cur_ch = front[i];
					for (char re = 'a'; re <= 'z'; ++re) {
						front[i] = re;
						if (remain.find(front) != remain.end()) {
							que.push(front);
						}
					 }
					front[i] = cur_ch;
				}
				--cur_size;
			}
			++level;
		}
		return 0;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string beginWord = "hit", endWord = "cog";
//	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
//
//	int ans = s.ladderLength(beginWord, endWord, wordList);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
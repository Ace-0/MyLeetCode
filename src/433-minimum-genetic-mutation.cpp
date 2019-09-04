// 433. Minimum Genetic Mutation


#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
		unordered_set<string> bank_set(bank.begin(), bank.end());
		unordered_set<string> visited;
		queue<string> que;
		vector<char> char_set = { 'A', 'C', 'G', 'T' };

		que.push(start);
		visited.insert(start);
		int step = 0;
		while (!que.empty()) {
			++step;
			int level_size = que.size();
			while (level_size > 0) {
				string cur_str = que.front();
				que.pop();
				for (int i = 0; i < 8; ++i) {
					string next_str = cur_str;
					for (char ch : char_set) {
						next_str[i] = ch;
						if (bank_set.find(next_str) != bank_set.end() && visited.find(next_str) == visited.end()) {
							if (next_str == end)
								return step;
							que.push(next_str);
							visited.insert(next_str);
						}
					}
				}
				--level_size;
			}
		}
		return -1;
    }
};

//int main() {
//	Solution s = Solution();
//
//	vector<string> bank = { "AAAACCCC", "AAACCCCC", "AACCCCCC" };
//	
//	int ans = s.minMutation("AAAAACCC", "AACCCCCC", bank);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
// 1048. Longest String Chain


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
public:
	int longestStrChain(vector<string>& words) {
		sort(words.begin(), words.end(), [](string s1, string s2) -> bool { return s1.length() < s2.length(); });
		int longest_chain = 1;
		for (int i = 0; i < words.size(); ++i) {
			dfs(words[i], 1, words, i + 1, longest_chain);
		}
		return longest_chain;
	}

	void dfs(string cur_str, int cur_chain_len, vector<string>& words, int start, int& longest_chain) {
		for (int i = start; i < words.size(); ++i) {
			if (words[i].length() == cur_str.length() + 1) {
				int p = 0, q = 0;
				while (p < cur_str.length() && q < words[i].length()) {
					if (cur_str[p] == words[i][q]) {
						++p;
						++q;
					}
					else {
						++q;
					}
				}
				if (p == q)
					++q;
				if (p == cur_str.length() && q == words[i].length()) {
					if (cur_chain_len + 1 > longest_chain)
						longest_chain = cur_chain_len + 1;
					dfs(words[i], cur_chain_len + 1, words, i + 1, longest_chain);
				}
			}
			if (words[i].length() > cur_str.length() + 1) {
				break;
			}
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<string> testcase = { "ksqvsyq", "ks", "kss", "czvh", "zczpzvdhx", "zczpzvh", "zczpzvhx", "zcpzvh", "zczvh", "gr", "grukmj", "ksqvsq", "gruj", "kssq", "ksqsq", "grukkmj", "grukj", "zczpzfvdhx", "gru" };
//	//vector<string> testcase = { "sgtnz","sgtz","sgz","ikrcyoglz","ajelpkpx","ajelpkpxm","srqgtnz","srqgotnz","srgtnz","ijkrcyoglz" };
//	//vector<string> testcase = { "a","b","ba","bca","bda","bdca" };
//
//	int ans = s.longestStrChain(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}

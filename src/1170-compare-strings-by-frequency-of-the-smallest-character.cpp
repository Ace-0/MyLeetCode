// 1170. Compare Strings by Frequency of the Smallest Character


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		int qSize = queries.size(), wSize = words.size();
        map<int, int> freqCnt;
		for (int i = 0; i < wSize; ++i) {
			char smallestCh = 'z' + 1;
			int freq = 0;
			for (char& ch : words[i]) {
				if (ch < smallestCh) {
					smallestCh = ch;
					freq = 1;
				}
				else if (ch == smallestCh) {
					++freq;
				}
			}
			++freqCnt[freq];
		}
		vector<int> result;
		for (int i = 0; i < qSize; ++i) {
			char smallestCh = 'z' + 1;
			int freq = 0;
			for (char& ch : queries[i]) {
				if (ch < smallestCh) {
					smallestCh = ch;
					freq = 1;
				}
				else if (ch == smallestCh) {
					++freq;
				}
			}
			auto it = freqCnt.upper_bound(freq);
			int count = 0;
			while (it != freqCnt.end()) {
				count += it->second;
				++it;
			}
			result.push_back(count);
		}
		return result;
    }
};

// int main() {
// 	Solution s = Solution();

// 	vector<string> queries = {"bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"};
// 	vector<string> words = {"aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"};
// 	//                         3       2       2        1     1        1       1      10           5         2   
// 	vector<int> ans = s.numSmallerByFrequency(queries, words);

// 	for (int n : ans) {
// 		cout << n << " ";
// 	}
// 	cout << endl;

// 	return 0;
// }

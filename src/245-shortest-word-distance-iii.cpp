// 245. Shortest Word Distance III


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int shortestWordDistance(vector<string>& words, string word1, string word2) {
		int last_first = -1, last_second = -1;
		int min_dist = words.size();
		int i = 0;
		while (i < words.size()) {
			if (words[i] == word1) {
				if (word1 == word2 && last_first != -1)
					min_dist = min(min_dist, abs(i - last_first));
				last_first = i;
			}
			else if (words[i] == word2) {
				last_second = i;
			}
			if (word1 != word2 && last_first != -1 && last_second != -1)
				min_dist = min(min_dist, abs(last_first - last_second));
			++i;
		}
		return min_dist;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<string> words = { "practice", "makes", "perfect", "coding", "makes" };
//	//string word1 = "coding", word2 = "practice";
//	string word1 = "makes", word2 = "makes";
//
//	int ans = s.shortestWordDistance(words, word1, word2);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}